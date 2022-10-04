#include "pch.h"
#include "ResourceManager.h"

void ResourceManager::init()
{
}

void ResourceManager::loadResource(std::string filepath, AudioResType type)
{
	auto fileName = std::filesystem::path(filepath).stem().string();
	auto fileExt = std::filesystem::path(filepath).extension().string();

	if (!std::filesystem::path(filepath).has_extension())
	{
		Log::Error("File at: " + filepath + " has no file extension and could not be loaded.");
		return;
	}

	if (fileExt == ".png" || fileExt == ".bmp" || fileExt == "jpeg")
	{
		_resources.emplace(fileName, std::make_shared<TextureResource>(filepath));
	}
	else if (fileExt == ".ogg" || fileExt == ".wav" || fileExt == ".mp3")
	{
		if (type == AudioResType::SFX)
		{
			_resources.emplace(fileName, std::make_shared<SoundResource>(filepath));
		}
		else if (type == AudioResType::MUSIC)
		{
			_resources.emplace(fileName, std::make_shared<MusicResource>(filepath));
		}
	}
	else if (fileExt == ".pmat")
	{
		// physic material
		_resources.emplace(fileName, std::make_shared<PhysicMaterialResource>(filepath));
	}
	else
	{
		Log::Error("Could not recognize extension for file at: " + filepath);
	}
}
