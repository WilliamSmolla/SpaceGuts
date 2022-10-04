#include "pch.h"
#include "GameObject.h"

GameObject::GameObject(entt::entity handle, Scene* scene)
	: _handle{ handle }, _scene{ scene } {}
