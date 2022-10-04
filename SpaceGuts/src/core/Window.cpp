#include "pch.h"
#include "Window.h"
#include "Log.h"

void Window::init()
{
	auto width = 1280;
	auto height = 960;

	_window = SDL_CreateWindow("SpaceGuts", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);

	if (_window == nullptr) {
		Log::Critical("Failed to Initialize Window.");
		exit(EXIT_FAILURE);
	}
	else
	{
		Log::Info("Window created successfully.");
	}

	SDL_DisplayMode DM;
	SDL_GetCurrentDisplayMode(0, &DM);
	auto Width = DM.w;
	auto Height = DM.h;

	_windowSize = Vec2(width, height);
	_windowScaledSize = Vec2(width / _metersToPixels, height / _metersToPixels);
}

SDL_Window* Window::getNativeWindow()
{
	return _window;
}

const char* Window::getTitle()
{
	return _title;
}

Vec2 Window::getSize()
{
	return _windowSize;;
}

Vec2 Window::getScaledSize()
{
	return _windowScaledSize;
}

void Window::setTitle(const char* title)
{
	SDL_SetWindowTitle(_window, title);
	_title = title;
}

void Window::setFullScreen()
{
	SDL_SetWindowFullscreen(_window, SDL_WINDOW_FULLSCREEN_DESKTOP);
}

void Window::setIcon(SDL_Surface* icon)
{
	SDL_SetWindowIcon(_window, icon);
}
