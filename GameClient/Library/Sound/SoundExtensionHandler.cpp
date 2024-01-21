#include "SoundExtensionHandler.h"

void handleWAV(ALuint* gBuffer, int index, const char* fileName)
{
	char* buffer = loadFile(fileName);

	WAVRiffHeader* riffHead = (WAVRiffHeader*)buffer;
	WAVFmtSubchunk* fmtSubchunk = (WAVFmtSubchunk*)&buffer[sizeof(WAVRiffHeader)];
	WAVDataSubchunk* dataSubchunk = (WAVDataSubchunk*)&buffer[sizeof(WAVRiffHeader) + sizeof(WAVFmtSubchunk) + (fmtSubchunk->fmtChunkSize - 16)];

	ALenum format;
	switch (fmtSubchunk->bitPerSample)
	{
		case 8:
		{
			format = fmtSubchunk->numChannels == 1 ? AL_FORMAT_MONO8 : AL_FORMAT_STEREO8;
			break;
		}
		case 16:
		{
			format = fmtSubchunk->numChannels == 1 ? AL_FORMAT_MONO16 : AL_FORMAT_STEREO16;
			break;
		}
		default:
		{
			throw std::runtime_error("error is occur in handleWAV during getting format");
			return;
		}
	}

	char* data = &buffer[sizeof(WAVRiffHeader) + sizeof(WAVFmtSubchunk) + (fmtSubchunk->fmtChunkSize - 16) + sizeof(WAVDataSubchunk)];
	unsigned int dataLength = dataSubchunk->dataChunkSize;
	unsigned int sampleRate = fmtSubchunk->sampleRate;

	alGetError();
	alBufferData(gBuffer[index], format, data, dataLength, sampleRate);
	delete[] buffer;
}


void handleMP3(ALuint* gBuffer, int index, const char* fileName)
{
	std::vector<uint8_t> audioData;
	AVFormatContext* formatContext = nullptr;
	if (avformat_open_input(&formatContext, fileName, NULL, NULL) != 0) 
	{
		throw std::runtime_error("error is occur in handleMP3 during opening file");
		return;
	}

	if (avformat_find_stream_info(formatContext, nullptr) < 0) 
	{
		avformat_close_input(&formatContext);
		throw std::runtime_error("error is occur in handleMP3 during finding stream");
		return;
	}

	int streamIndex = av_find_best_stream(formatContext, AVMEDIA_TYPE_AUDIO, -1, -1, NULL, 0);
	if (streamIndex < 0) 
	{
		avformat_close_input(&formatContext);
		throw std::runtime_error("error is occur in handleMP3 during finding stream index");
		return;
	}

#if _DEBUG
	av_dump_format(formatContext, 0, fileName, false);
#endif

	AVStream* audioStream = formatContext->streams[streamIndex];
	AVCodecParameters* codecParameters = audioStream->codecpar;
	const AVCodec* codec = avcodec_find_decoder(codecParameters->codec_id);
	AVCodecContext* codecContext = avcodec_alloc_context3(codec);
	avcodec_parameters_to_context(codecContext, codecParameters);
	if (avcodec_open2(codecContext, codec, nullptr) < 0) 
	{
		avcodec_free_context(&codecContext);
		avformat_close_input(&formatContext);
		throw std::runtime_error("error is occur in handleMP3 during open codec");
		return;
	}

	AVPacket* packet = av_packet_alloc();
	AVFrame* frame = av_frame_alloc();

	while (av_read_frame(formatContext, packet) >= 0) 
	{
		if (packet->stream_index == streamIndex) 
		{
			if (avcodec_send_packet(codecContext, packet) == 0) 
			{
				while (avcodec_receive_frame(codecContext, frame) == 0) 
				{
					if (codecContext->sample_fmt == AV_SAMPLE_FMT_FLTP) 
					{
						int numSamples = frame->nb_samples;
						int channels = codecContext->channels;

						for (int i = 0; i < numSamples; ++i) 
						{
							for (int ch = 0; ch < channels; ++ch) 
							{
								float sample = reinterpret_cast<float*>(frame->data[ch])[i];
								if (sample < -1.0f)
								{
									sample = -1.0f;
								}
								else if (sample > 1.0f)
								{
									sample = 1.0f;
								}
								int16_t intSample = (int16_t)(sample * 32767.0f);
								// 8bit 변환 + little endian 처리
								audioData.push_back((uint8_t)(intSample & 0xFF));
								audioData.push_back((uint8_t)((intSample >> 8) & 0xFF));
							}
						}
					}
					else 
					{
						// 다른 포맷 처리
						int dataSize = frame->linesize[0];
						audioData.insert(audioData.end(), frame->data[0], frame->data[0] + dataSize);
					}
				}
			}
		}
		av_packet_unref(packet);
	}

	ALenum format;
	if (codecContext->channels == 1) 
	{
		format = (codecContext->sample_fmt == AV_SAMPLE_FMT_U8) ? AL_FORMAT_MONO8 : AL_FORMAT_MONO16;
	}
	else 
	{
		format = (codecContext->sample_fmt == AV_SAMPLE_FMT_U8) ? AL_FORMAT_STEREO8 : AL_FORMAT_STEREO16;
	}

	alGetError();
	alBufferData(gBuffer[index], format, audioData.data(), (ALsizei)(audioData.size()), codecContext->sample_rate);

	av_frame_free(&frame);
	avcodec_free_context(&codecContext);
	avformat_close_input(&formatContext);
}
