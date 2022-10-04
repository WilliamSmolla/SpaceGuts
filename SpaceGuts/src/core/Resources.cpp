#include "pch.h"
#include "Resources.h"

Resource::Resource(std::string filepath)
	: filepath{ filepath } {}

TextureResource::TextureResource(std::string filepath)
	: Resource{ filepath }
{
	texture = std::make_shared<Texture>(IMG_LoadTexture(Renderer::GetNativeRenderer(), filepath.c_str()));
}

TextureResource::~TextureResource()
{
}

SoundResource::SoundResource(std::string filepath)
	: Resource{ filepath }
{
	sound = Mix_LoadWAV(filepath.c_str());
}

SoundResource::~SoundResource()
{
	Mix_FreeChunk(sound);
}

MusicResource::MusicResource(std::string filepath)
	: Resource{ filepath }
{
	music = Mix_LoadMUS(filepath.c_str());
}

MusicResource::~MusicResource()
{
	Mix_FreeMusic(music);
}

PhysicMaterialResource::PhysicMaterialResource(std::string filepath)
	: Resource{ filepath }
{

}

PhysicMaterialResource::~PhysicMaterialResource()
{
}
