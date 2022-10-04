#include "pch.h"
#include "SoundManager.h"
#include "Log.h"

void SoundManager::init()
{
}

void SoundManager::playSFX(std::string name, int channel, MixOption option)
{
	Mix_PlayChannel(channel, ResourceManager::GetResource<SoundResource>(name)->sound, (int)option);
}

void SoundManager::playMusic(std::string name, MixOption option)
{
	Mix_PlayMusic(ResourceManager::GetResource<MusicResource>(name)->music, (int)option);
}

void SoundManager::pauseMusic()
{
	Mix_PauseMusic();
}

void SoundManager::stopMusic()
{
	Mix_HaltMusic();
}

void SoundManager::resumeMusic()
{
	Mix_ResumeMusic();
}
