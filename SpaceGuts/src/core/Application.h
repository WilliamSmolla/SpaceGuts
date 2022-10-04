#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "../core/Window.h"
#include "../graphics/Renderer.h"
#include "ResourceManager.h"
#include "SoundManager.h"
#include "core/InputManager.h"
#include "physics/PhysicsManager.h"
#include "scene/SceneManager.h"

class Application
{
public:
	Application();
	~Application();

	void Run();
	void Shutdown();

	virtual void HandleEvents(const SDL_Event& event) = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void Render() = 0;
	
private:
	void initSDL();

	Scene* _scene;
	bool _isRunning;
	unsigned int _frameTime = 16;
};

