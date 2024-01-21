#pragma once

#include "GameLibrary.h"

struct InitBufferData
{
	ALenum format;
	const char* data;
	unsigned int dataLength;
	unsigned int samplesPerSec;
};

typedef void (*HandlerFunction)(ALuint*, int, const char*);

struct SoundExtensionHandler
{
	const char* extension;
	HandlerFunction handler;
};

void handleWAV(ALuint* gBuffer, int index, const char* buffer);
void handleMP3(ALuint* gBuffer, int index, const char* buffer);

static SoundExtensionHandler soundExtensionHandler[] =
{
	{"wav", handleWAV},
	{"mp3", handleMP3},
	{NULL, NULL}
};
