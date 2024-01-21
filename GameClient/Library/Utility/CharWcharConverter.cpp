#include "CharWcharConverter.h"

const char* wcharToChar(const wchar_t* input)
{
	const size_t length = wcslen(input);
	char* output = new char[length + 1];
	wcstombs(output, input, length);

	return output;
}

const wchar_t* charToWchar(const char* input)
{
	const size_t length = strlen(input);
	wchar_t* output = new wchar_t[length + 1];
	mbstowcs(output, input, length);

	return output;
}