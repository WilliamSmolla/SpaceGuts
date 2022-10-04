#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <box2d/b2_body.h>
#include "maths/Vec2.h"

class Window
{
public:
	static Window& GetInstance()
	{
		static Window instance;
		return instance;
	}

	Window(Window const&) = delete;
	void operator=(Window const&) = delete;

	static void Init() { GetInstance().init(); }
	static SDL_Window* GetNativeWindow() { return GetInstance().getNativeWindow(); }
	static const char* GetTitle() { return GetInstance().getTitle(); }
	static Vec2 GetSize() { return GetInstance().getSize(); }
	static Vec2 GetScaledSize() { return GetInstance().getScaledSize(); }
	static int GetM2PRatio() { return GetInstance().getM2PRatio(); }
	static void SetTitle(const char* title) { GetInstance().setTitle(title); }
	static void SetIcon(SDL_Surface* icon) { GetInstance().setIcon(icon); }
	static void SetFullScreen() { GetInstance().setFullScreen(); }

private:
	Window(){}

	void init();
	SDL_Window* getNativeWindow();
	const char* getTitle();
	Vec2 getSize();
	Vec2 getScaledSize();
	int getM2PRatio() { return _metersToPixels; }
	void setTitle(const char* title);
	void setIcon(SDL_Surface* icon);
	void setFullScreen();

	SDL_Window* _window = NULL;
	const char* _title = "";
	int _metersToPixels = 50;
	Vec2 _windowSize;
	Vec2 _windowScaledSize;
	SDL_Surface* _icon = NULL;
};

