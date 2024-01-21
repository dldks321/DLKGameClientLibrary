#pragma once

#include "GameLibrary.h"

struct WAVRiffHeader
{
	char riffChunkID[4];
	unsigned int riffChunkSize;
	char riffFormat[4];
};

struct WAVFmtSubchunk
{
	char fmtChunkID[4];
	unsigned int fmtChunkSize;
	unsigned short audioFormat;
	unsigned short numChannels;
	unsigned int sampleRate;
	unsigned int byteRate;
	unsigned short blockAlign;
	unsigned short bitPerSample;
};

struct WAVDataSubchunk
{
	char dataChunkID[4];
	unsigned int dataChunkSize;
};