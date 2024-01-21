#include "KeyboardInput.h"

void rpgKeySetting(const wchar_t* settingFileName, std::unordered_map<int, KeyType>* keyboardMapper)
{
	keyboardMapper->insert({ GetPrivateProfileInt(L"Keyboard", L"MoveUp", 0x26, settingFileName), KeyType::KeyTypeUp });
	keyboardMapper->insert({ GetPrivateProfileInt(L"Keyboard", L"MoveDown", 0x28, settingFileName), KeyType::KeyTypeDown });
	keyboardMapper->insert({ GetPrivateProfileInt(L"Keyboard", L"MoveLeft", 0x25, settingFileName), KeyType::KeyTypeLeft });
	keyboardMapper->insert({ GetPrivateProfileInt(L"Keyboard", L"MoveRight", 0x27, settingFileName), KeyType::KeyTypeRight });
	keyboardMapper->insert({ GetPrivateProfileInt(L"Keyboard", L"Jump", 0x43, settingFileName), KeyType::KeyTypeJump });
	keyboardMapper->insert({ GetPrivateProfileInt(L"Keyboard", L"Attack", 0x58, settingFileName), KeyType::KeyTypeAttack });
	keyboardMapper->insert({ GetPrivateProfileInt(L"Keyboard", L"Skill", 0x5a, settingFileName), KeyType::KeyTypeSkill });
	keyboardMapper->insert({ GetPrivateProfileInt(L"Keyboard", L"Escape", 0x1b, settingFileName), KeyType::KeyTypeEscape });
}

KeyboardInput::KeyboardInput(const char* settingFileName, KeySettingFunction settingFunction)
{
	keyboardMapper = new std::unordered_map<int, KeyType>;
	keyboardInput = new std::unordered_set<int>;

	keySettingFunction = settingFunction;

	const wchar_t* wcharFileName = charToWchar(settingFileName);
	//printf_s("wchar printing : %ls \n", wcharFileName);
	keySettingFunction(wcharFileName, keyboardMapper);

	delete[] wcharFileName;
}

KeyboardInput::~KeyboardInput()
{
	delete keyboardMapper;
	delete keyboardInput;
}

void KeyboardInput::updateKeyboardInput(KeyState keyState, int input)
{
	KeyType keyType;
	if (keyboardMapper->find(input) == keyboardMapper->end())
	{
		return;
	}
	keyType = keyboardMapper->find(input)->second;
	switch (keyState)
	{
		case(KeyStateDown):
		{
			if (keyboardInput->find(keyType) != keyboardInput->end())
			{
				return;
			}
			keyboardInput->insert(keyType);
			//printf_s("key %d is inputed\n", keyType);
			break;
		}
		case(KeyStateUp):
		{
			if (keyboardInput->find(keyType) == keyboardInput->end())
			{
				return;
			}
			keyboardInput->erase(keyType);
			//printf_s("key %d is eliminated\n", keyType);
			break;
		}
	}
}

void KeyboardInput::mapperSetting(const char* settingFileName, KeyType keyType, const char* keyName, int afterSignal)
{
	for (auto& pair : *keyboardMapper)
	{
		if (pair.second == keyType)
		{
			keyboardMapper->erase(pair.first);
			keyboardMapper->insert({ afterSignal, keyType });

			const wchar_t* wcharFileName = charToWchar(settingFileName);
			const wchar_t* wcharKeyName = charToWchar(keyName);
			std::wstring wcharSignal = std::to_wstring(afterSignal);
			WritePrivateProfileString(L"Keyboard", wcharKeyName, wcharSignal.c_str(), wcharFileName);
			delete[] wcharFileName;
			delete[] wcharKeyName;

			return;
		}
	}
}