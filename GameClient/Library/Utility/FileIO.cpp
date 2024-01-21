#include "FileIO.h"

char* loadFile(const char* name)
{
	FILE* file = NULL;
	errno_t error;

	error = fopen_s(&file, name, "rb");

	if (error != 0)
		return NULL;

	fseek(file, 0, SEEK_END);
	int len = ftell(file);

	fseek(file, 0, SEEK_SET);

	char* buffer = new char[len + 1];
	fread(buffer, sizeof(char), len, file);
	buffer[len] = '\0';

	fclose(file);

	return buffer;
}

void saveFile(const char* name, char* buffer, int bufferLength)
{
	FILE* file = NULL;
	errno_t error;

	error = fopen_s(&file, name, "wb");

	if (error != 0)
	{
		printf_s("File Open Failed");
		return;
	}

	fwrite(buffer, sizeof(char), bufferLength, file);

	fclose(file);
}