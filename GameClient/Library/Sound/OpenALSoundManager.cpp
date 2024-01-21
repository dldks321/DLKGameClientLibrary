#include "OpenALSoundManager.h"

OpenALSoundManager::OpenALSoundManager(int audioNum) 
	: OpenALSoundManager::OpenALSoundManager(
		audioNum, 
		AudioContextOption{44100, 16, 4, 0, 0, UseFrequency | UseMonoSources | UseStereoSources }
	)
{ }

OpenALSoundManager::OpenALSoundManager(int audioNum, const AudioContextOption& contextOption)
{
	bufCount = audioNum;
	gBuffer = new ALuint[audioNum];
	gSource = new ALuint[audioNum];

	ALCdevice* newDevice = NULL;
	ALCcontext* newContext = NULL;
	ALenum error;

	try {
		newDevice = alcOpenDevice(NULL);

		if (newDevice == nullptr)
		{
			throw std::runtime_error("Fail to opening Device");
		}

		std::vector<ALCint> attrlist;
		if (contextOption.usingOptions & UseFrequency)
		{
			attrlist.push_back(ALC_FREQUENCY);
			attrlist.push_back(contextOption.frequency);
		}
		if (contextOption.usingOptions & UseMonoSources)
		{
			attrlist.push_back(ALC_MONO_SOURCES);
			attrlist.push_back(contextOption.monoSources);
		}
		if (contextOption.usingOptions & UseStereoSources)
		{
			attrlist.push_back(ALC_STEREO_SOURCES);
			attrlist.push_back(contextOption.stereoSources);
		}
		if (contextOption.usingOptions & UseRefresh)
		{
			attrlist.push_back(ALC_REFRESH);
			attrlist.push_back(contextOption.refresh);
		}
		if (contextOption.usingOptions & UseSync)
		{
			attrlist.push_back(ALC_SYNC);
			attrlist.push_back(contextOption.sync);
		}
		attrlist.push_back(0);

		newContext = alcCreateContext(newDevice, attrlist.data());
		if (newContext == nullptr)
		{
			throw std::runtime_error("Fail to opening Context");
		}

		alcMakeContextCurrent(newContext);

		alGenBuffers((ALsizei)audioNum, gBuffer);
		if ((error = alGetError()) != AL_NO_ERROR)
		{
			printf_s("error is occur in alGenBuffers : %d\n", error);
			throw std::runtime_error("error is occur in alGenBuffers");
		}

		alGenSources((ALsizei)audioNum, gSource);
		if ((error = alGetError()) != AL_NO_ERROR)
		{
			printf_s("error is occur in alGenSources : %d\n", error);
			throw std::runtime_error("error is occur in alGenSources");
		}
	} catch (const std::exception e) {
		if (alIsBuffer(*gBuffer) == AL_TRUE)
		{
			alDeleteBuffers(bufCount, gBuffer);
		}
		if (alIsSource(*gSource) == AL_TRUE)
		{
			alDeleteSources(bufCount, gSource);
		}

		delete[] gBuffer;
		delete[] gSource;

		if (newContext == nullptr)
		{
			alcDestroyContext(newContext);
		}
		if (newDevice == nullptr)
		{
			alcCloseDevice(newDevice);
		}
		throw;
	}
}

OpenALSoundManager::~OpenALSoundManager()
{
	alDeleteBuffers(bufCount, gBuffer);
	alDeleteSources(bufCount, gSource);

	delete[] gBuffer;
	delete[] gSource;

	ALCcontext* context = alcGetCurrentContext();
	ALCdevice* device = alcGetContextsDevice(context);
	alcDestroyContext(context);
	alcCloseDevice(device);
}

void OpenALSoundManager::initBuffer(int index, const char* vaFormat, ...)
{
	char vaString[MAX_FILENAME_LENGTH];

	va_list arg;
	va_start(arg, vaFormat);
	_vsnprintf_s(vaString, sizeof(vaString), vaFormat, arg);
	va_end(arg);

	const char* dotPosition = strrchr(vaFormat, '.');
	const char* fileExtension = (dotPosition == NULL) ? "" : dotPosition + 1;

	if (strcmp(fileExtension, "") == 0)
	{
		throw std::runtime_error("audio file format is wrong");
		return;
	}

	for (int i = 0; soundExtensionHandler[i].extension != NULL; i++)
	{
		if (strcmp(fileExtension, soundExtensionHandler[i].extension) == 0)
		{
			soundExtensionHandler[i].handler(gBuffer, index, vaFormat);
			break;
		}
	}

	ALenum error;
	if ((error = alGetError()) != AL_NO_ERROR)
	{
		throw std::runtime_error("error is occur in alBufferData during initBuffer");
		return;
	}
}

void OpenALSoundManager::initSource(int index, bool repeat)
{
	alGetError();// clear error list

	alSourcei(gSource[index], AL_LOOPING, repeat);

	ALfloat position[] = {0.0f, 0.0f, 0.0f};
	alSourcefv(gSource[index], AL_POSITION, position);

	alSourcef(gSource[index], AL_REFERENCE_DISTANCE, 50.0f);

	alSourcei(gSource[index], AL_BUFFER, gBuffer[index]);

	ALenum error;
	if ((error = alGetError()) != AL_NO_ERROR)
	{
		throw std::runtime_error("error is occur in initSource");
	}
}

void OpenALSoundManager::updateSource()
{

}

void OpenALSoundManager::play(int index)
{
	alSourcePlay(gSource[index]);
	ALenum error;
	if ((error = alGetError()) != AL_NO_ERROR)
	{
		throw std::runtime_error("error is occur in sound play");
	}
}

void OpenALSoundManager::pause(int index)
{
	alSourcePause(gSource[index]);
	ALenum error;
	if ((error = alGetError()) != AL_NO_ERROR)
	{
		throw std::runtime_error("error is occur in sound pause");
	}
}

void OpenALSoundManager::stop(int index)
{
	alSourceStop(gSource[index]);
	ALenum error;
	if ((error = alGetError()) != AL_NO_ERROR)
	{
		throw std::runtime_error("error is occur in sound stop");
	}
}

void OpenALSoundManager::volume(int index, float vol)
{
	alSourcef(gSource[index], AL_GAIN, vol);
	ALenum error;
	if ((error = alGetError()) != AL_NO_ERROR)
	{
		throw std::runtime_error("error is occur in sound volume");
	}
}