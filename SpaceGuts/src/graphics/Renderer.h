#pragma once
#include "Texture.h"
#include "../maths/Maths.h"
#include "entt/entt.hpp"

// TODO: Implement basic frustrum culling

class Scene;

class Renderer
{
public:
	static Renderer& GetInstance()
	{
		static Renderer instance; 
		return instance;
	}

	Renderer(Renderer const&) = delete;
	void operator=(Renderer const&) = delete;

	static void Init() { GetInstance().init(); }
	static void Shutdown() { GetInstance().shutdown(); }

	static void Render(entt::registry& registry, Scene* scene) { GetInstance().render(registry, scene); }

	static SDL_Renderer* GetNativeRenderer() { return GetInstance().getNativeRenderer(); }
	static void RenderClear(Vec4 color) { GetInstance().renderClear(color); }
	static void RenderPresent() { GetInstance().renderPresent(); }

private:
	Renderer(){}

	void init();
	void shutdown();

	void render(entt::registry& registry, Scene* scene);

	SDL_Renderer* getNativeRenderer();
	void renderClear(Vec4 color);
	void renderPresent();

	SDL_Renderer* _renderer = nullptr;
};

