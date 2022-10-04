#pragma once
#include "AnimationClip.h"
#include "Texture.h"

class AnimationController
{
public:
	AnimationController();

	void Update(float deltaTime);
	void AddAnimation(std::string state,
		std::shared_ptr<AnimationClip> animClip);
	void SetAnimationState(std::string state);
	const std::string& GetAnimationState() const;
	SDL_Rect GetSourceQuad() const;

private:
	SDL_Rect _sourceQuad;
	std::map<std::string, std::shared_ptr<AnimationClip>> _animations;
	std::pair<std::string, std::shared_ptr<AnimationClip>> _currentAnimation;
};

