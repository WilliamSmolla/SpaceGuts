#pragma once
#include "ResourceManager.h"

enum class MixOption
{
	REPEAT = -1,
	NO_REPEAT = 0
};

class SoundManager
{
public:
	static SoundManager& GetInstance()
	{
		static SoundManager instance;
		return instance;
	}

	SoundManager(SoundManager const&) = delete;
	void operator=(SoundManager const&) = delete;

	static void Init() { GetInstance().init(); }
	static void PlaySFX(std::string name, int channel, MixOption option) { GetInstance().playSFX(name, channel, option); }
	static void PlayMusic(std::string name, MixOption option) { GetInstance().playMusic(name, option); }
	static void PauseMusic() { GetInstance().pauseMusic(); }
	static void ResumeMusic() { GetInstance().resumeMusic(); }
	static void StopMusic() { GetInstance().stopMusic(); }

private:
	SoundManager() {}

	void init();
	void playSFX(std::string name, int channel, MixOption option);
	void playMusic(std::string name, MixOption option);
	void pauseMusic();
	void resumeMusic();
	void stopMusic();
};

