#pragma once

#define DEV_WIDTH 1280
#define DEV_HEIGHT 720

#define MAX_FILENAME_LENGTH 1024

typedef char int8;
typedef unsigned char uint8;
typedef short int16;
typedef unsigned short uint16;
typedef int int32;
typedef unsigned int uint32;

typedef float float32;
typedef double float64;

typedef unsigned char byte;

enum KeyState
{
	KeyStateDown,
	KeyStateMove,
	KeyStateUp
};

enum KeyType
{
	KeyTypeUp,
	KeyTypeDown,
	KeyTypeLeft,
	KeyTypeRight,
	KeyTypeJump,
	KeyTypeAttack,
	KeyTypeSkill,

	KeyTypeEscape
};

enum Direction
{
	Top = 1,
	Bottom = 2,
	Right = 4,
	Left = 8
};

enum ObjectState
{
	Stop,
	Moving,
	Attack
};