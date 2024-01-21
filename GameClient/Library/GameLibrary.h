#pragma once

#if _DEBUG
#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console")
#endif

#pragma warning (disable : 4996)

//#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.
#include "targetver.h"

// C 런타임 헤더 파일입니다.
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

#include <windows.h>
#include <gdiplus.h>
#pragma comment (lib, "Gdiplus.lib")
using namespace Gdiplus;

#include <al.h>
#include <alc.h>
#pragma comment(lib, "OpenAL32.lib")

extern "C" {
	#include <libavformat/avformat.h>
	#include <libavcodec/avcodec.h>
	#include <libavutil/frame.h>
	#include <libavutil/mem.h>
	#include <libswresample/swresample.h>
	#pragma comment(lib, "avformat.lib")
	#pragma comment(lib, "avcodec.lib")
	#pragma comment(lib, "avutil.lib")
	#pragma comment(lib, "swresample.lib")
}

// C++ 헤더 파일
#include <vector>
#include <stdexcept>
#include <cstdarg>
#include <string>
#include <unordered_map>
#include <unordered_set>

#include "Object.h"
#include "Player.h"
#include "Scene.h"
#include "SceneManager.h"

#include "Color.h"

#include "KeyboardInput.h"
#include "MouseInput.h"

#include "Point.h"
#include "Vector.h"

#include "Cylinder3D.h"
#include "Rectangle2D.h"
#include "Collision.h"
#include "Physics.h"

#include "OpenALSoundManager.h"
#include "SoundExtensionHandler.h"
#include "SoundHeader.h"

#include "CharWcharConverter.h"
#include "FileIO.h"
#include "GameData.h"
#include "SettingData.h"

#include "Define.h"