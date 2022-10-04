#pragma once
#include <SDL.h>
#include "scene/ScriptableGameObject.h"
#include "box2d/box2d.h"

// Basic player controller for testing.
class PlayerController : public ScriptableGameObject
{
public:
	PlayerController() = default;
	~PlayerController() {}

	virtual void OnCreate() override;
	virtual void OnDestroy() override;
	virtual void Update(float deltaTime) override;

	bool isGrounded = false;
	bool isReleased = true;
};

