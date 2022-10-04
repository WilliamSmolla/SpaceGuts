#pragma once
#include <SDL_mixer.h>
#include "graphics/Renderer.h"
#include "graphics/Texture.h"
#include "physics/PhysicMaterial.h"

struct Resource
{
	Resource(std::string filepath);
	virtual ~Resource() = default;

	std::string filepath;
};

struct TextureResource : public Resource
{
	TextureResource(std::string filepath);
	~TextureResource();
	
	std::shared_ptr<Texture> texture;
};

struct PhysicMaterialResource : public Resource
{
	PhysicMaterialResource(std::string filepath);
	~PhysicMaterialResource();

	std::shared_ptr<PhysicMaterial> material = nullptr;
};

// In the future, implement an other audio API. This is janky to separate music and sounds files.
struct SoundResource : public Resource
{
	SoundResource(std::string filepath);
	~SoundResource();

	Mix_Chunk* sound;
};

struct MusicResource : public Resource
{
	MusicResource(std::string filepath);
	~MusicResource();

	Mix_Music* music;
};

