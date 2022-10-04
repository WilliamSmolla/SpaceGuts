#pragma once
#include "box2d/box2d.h"
#include "scene/GameObject.h"

class PlayerGroundedCallback : public b2ContactListener
{
public:
	PlayerGroundedCallback();
	~PlayerGroundedCallback();

	virtual void BeginContact(b2Contact* contact) override;
	virtual void EndContact(b2Contact* contact) override;

private:
	GameObject gameObject;
};

