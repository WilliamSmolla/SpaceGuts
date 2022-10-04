#pragma once
#include <SDL.h>
#include "maths/Vec2.h"

// include in a more multi purpose event system in the future.
enum class Keycode
{
	A = 97,
	B = 98,
	C = 99,
	D = 100,
	E = 101,
	F = 102,
	G = 103,
	H = 104,
	I = 105,
	J = 106,
	K = 107,
	L = 108,
	M = 109,
	N = 110,
	O = 111,
	P = 112,
	Q = 113,
	R = 114,
	S = 115,
	T = 116,
	U = 117,
	V = 118,
	W = 119,
	X = 120,
	Y = 121,
	Z = 122,

	ESCAPE = 27,
	LEFT_SHIFT = 1073742049,
	RIGHT_SHIFT = 1073742053,
	LEFT_CTRL = 1073742048,
	RIGHT_CTRL = 1073742052,
	LEFT_ALT = 1073742050,
	RIGHT_ALT = 1073742054,
	SPACE = 32,
	ENTER = 13,
	LEFT = 1073741904,
	RIGHT = 1073741903,
	UP = 1073741906,
	DOWN = 1073741905,
};

enum class Mousecode
{
	LEFT_MOUSE = 1,
	RIGHT_MOUSE = 3
};

class InputManager
{
public:
	static InputManager& GetInstance()
	{
		static InputManager instance;
		return instance;
	}

	InputManager(InputManager const&) = delete;
	void operator=(InputManager const&) = delete;

	static void Init() { GetInstance().init(); }
	static void UpdateInputs(const SDL_Event& event) { GetInstance().updateInputs(event); }

	static bool IsKeyDown(Keycode keycode) { return GetInstance().isKeyDown(keycode); }
	static bool IsMouseButtonDown(Mousecode mousecode) { return GetInstance().isMouseButtonDown(mousecode); }
	static Vec2 GetCursorPosition() { GetInstance().getCursorPosition(); }

private:
	InputManager() {}

	void init();
	void updateInputs(const SDL_Event& event);
	void setKey(Keycode keycode, bool isKeyDown);
	void setButton(Mousecode mousecode, bool isButtonDown);
	bool isKeyDown(Keycode keycode);
	bool isMouseButtonDown(Mousecode mousecode);
	Vec2 getCursorPosition();

	std::unordered_map<Keycode, bool> _keycodes;
	std::unordered_map<Mousecode, bool> _mousecodes;
};

