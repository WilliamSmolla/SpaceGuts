#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <SDL_FontCache.h>
#include "../graphics/Texture.h"
#include "../graphics/Renderer.h"
#include "../scene/GameObject.h"
#include "Log.h"
#include "Resources.h"
#include "scene/Scene.h"

// change audio API in the future
enum class AudioResType
{
	NONE = 0,
	SFX = 1,
	MUSIC = 2
};

class ResourceManager
{
public:
	static ResourceManager& GetInstance()
	{
		static ResourceManager instance;
		return instance;
	}

	ResourceManager(ResourceManager const&) = delete;
	void operator=(ResourceManager const&) = delete;

	static void Init() { GetInstance().init(); }
	static void LoadResource(std::string filepath, AudioResType type = AudioResType::NONE) { GetInstance().loadResource(filepath, type); }

	template<typename T>
	static std::shared_ptr<T> GetResource(std::string name)
	{	
		return GetInstance().getResource<T>(name);
	}

private:
	ResourceManager(){}

	void init();	
	void loadResource(std::string filepath, AudioResType type = AudioResType::NONE);

	template<typename T>
	std::shared_ptr<T> getResource(std::string name)
	{
		return dynamic_pointer_cast<T>(_resources[name]);
	}
	
	std::unordered_map<std::string, std::shared_ptr<Resource>> _resources;	
};

