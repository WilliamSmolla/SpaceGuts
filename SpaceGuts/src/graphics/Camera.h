#pragma once
#include <entt/entt.hpp>
#include "maths/Vec2.h"

class Scene;

class Camera
{
public:
	Camera();
	~Camera();

	void SetTarget(entt::entity target);
	void Update(Scene* scene);
	Vec2 GetPosition() const { return _position; }

private:
	Vec2 _position;
	entt::entity _target;
};

