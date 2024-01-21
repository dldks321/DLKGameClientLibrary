#pragma once

#include "GameLibrary.h"

char* loadFile(const char* name);
void saveFile(const char* name, char* buf, int bufLength);