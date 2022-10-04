#include "pch.h"
#include "AnimationClip.h"

AnimationClip::AnimationClip()
	: _frames{ 0 }, _currentFrameID{ 0 },
	_currentFrameTime{ 0 }, _isLooped{ true } {}

AnimationClip::~AnimationClip() {}

void AnimationClip::AddFrame(int x, int y,
	int width, int height, float frameTime)
{
	AnimationFrame frame;
	frame.width = width;
	frame.height = height;
	frame.x = x;
	frame.y = y;
	frame.frameTime = frameTime;
	_frames.push_back(frame);
}

const AnimationFrame* AnimationClip::GetCurrentFrame() const
{
	if (_frames.size() > 0)
	{
		return &_frames[_currentFrameID];
	}
	return nullptr;
}

bool AnimationClip::Update(float deltaTime)
{
	if (_frames.size() > 0)
	{
		_currentFrameTime += deltaTime;

		if (_currentFrameID == _frames.size() - 1 && !_isLooped)
		{
			_currentFrameTime = 0.0f;
			return false;
		}

		if (_currentFrameTime >= _frames[_currentFrameID].frameTime)
		{
			_currentFrameTime = 0.0f;
			incrementFrame();
			return true;
		}
		return false;
	}
}

void AnimationClip::Reset()
{
	_currentFrameID = 0;
	_currentFrameTime = 0.0f;
}

bool AnimationClip::IsLooped() const
{
	return _isLooped;
}

void AnimationClip::SetIsLooped(bool isLooped)
{
	_isLooped = isLooped;
}

void AnimationClip::incrementFrame()
{
	_currentFrameID = (_currentFrameID + 1) % _frames.size();
}
