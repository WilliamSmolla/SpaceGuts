#include "pch.h"
#include "AnimationController.h"

AnimationController::AnimationController()
	: _currentAnimation{ "", nullptr }, _sourceQuad{ SDL_Rect() } {}

void AnimationController::Update(float deltaTime)
{
	if (_currentAnimation.first != "")
	{
		bool newFrame = _currentAnimation.second->Update(deltaTime);

		if (newFrame)
		{
			auto frame = _currentAnimation.second->GetCurrentFrame();

			_sourceQuad.x = frame->x;
			_sourceQuad.y = frame->y;
			_sourceQuad.w = frame->width;
			_sourceQuad.h = frame->height;
		}
	}
}

void AnimationController::AddAnimation(std::string state, std::shared_ptr<AnimationClip> animClip)
{
	auto inserted = _animations.insert(std::make_pair(state, animClip));
	if (_currentAnimation.first == "")
	{
		SetAnimationState(state);
	}
}

void AnimationController::SetAnimationState(std::string state)
{
	if (_currentAnimation.first == state) { return; }

	auto animation = _animations.find(state);
	if (animation != _animations.end())
	{
		_currentAnimation.first = animation->first;
		_currentAnimation.second = animation->second;
		_currentAnimation.second->Reset();
	}
}

const std::string& AnimationController::GetAnimationState() const
{
	return _currentAnimation.first;
}

SDL_Rect AnimationController::GetSourceQuad() const
{
	return _sourceQuad;
}
