#pragma once

#include "GameLibrary.h"

const unsigned int UseFrequency = 0b10000;
const unsigned int UseMonoSources = 0b01000;
const unsigned int UseStereoSources = 0b00100;
const unsigned int UseRefresh = 0b00010;
const unsigned int UseSync = 0b00001;

struct AudioContextOption 
{
	ALuint frequency = 0;
	ALuint monoSources = 0;
	ALuint stereoSources = 0;
	ALuint refresh = 0;
	ALuint sync = 0;
	unsigned int usingOptions = 0;
};

class OpenALSoundManager
{
public:
	OpenALSoundManager(int audioNum);
	OpenALSoundManager(int audioNum, const AudioContextOption& contextOption);
	~OpenALSoundManager();

	void initBuffer(int index, const char* vaFormat, ...);
	void initSource(int index, bool repeat);
	void updateSource();

	void play(int index);
	void pause(int index);
	void stop(int index);
	void volume(int index, float vol);

private:
	int bufCount;
	ALuint* gBuffer;
	ALuint* gSource;
};