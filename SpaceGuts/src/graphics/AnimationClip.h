#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "graphics/Texture.h"
#include "maths/Vec2.h"

struct AnimationFrame
{
	int width;
	int height;
	int x;
	int y;
	float frameTime;
};

class AnimationClip
{
public:
	AnimationClip();
	~AnimationClip();

	void AddFrame(int x, int y, int width, int height, float frameTime);

	const AnimationFrame* GetCurrentFrame() const;
	bool Update(float deltaTime);
	void Reset();
	bool IsLooped() const;
	void SetIsLooped(bool isLooped);

private: 
	void incrementFrame();
	std::vector<AnimationFrame> _frames;
	int _currentFrameID;
	float _currentFrameTime;
	bool _isLooped;
};

