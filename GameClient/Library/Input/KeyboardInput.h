#pragma once

#include "GameLibrary.h"

typedef void (*KeySettingFunction)(const wchar_t*, std::unordered_map<int, KeyType>*);

void rpgKeySetting(const wchar_t* settingFileName, std::unordered_map<int, KeyType>* keyboardMapper);

class KeyboardInput
{
private:
	std::unordered_map<int, KeyType>* keyboardMapper;
	std::unordered_set<int>* keyboardInput;
	KeySettingFunction keySettingFunction;
public:
	KeyboardInput(const char* settingFileName, KeySettingFunction settingFunction);
	~KeyboardInput();
	void updateKeyboardInput(KeyState keyState, int input);
	void mapperSetting(const char* settingFileName, KeyType keyType, const char* keyName, int afterSignal);
};