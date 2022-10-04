#include "pch.h"
#include "Camera.h"
#include "scene/Components.h"
#include "core/Window.h"
#include "scene/GameObject.h"
#include "scene/Scene.h"

Camera::Camera()
{
}

Camera::~Camera()
{
}

void Camera::SetTarget(entt::entity target)
{
	_target = target;
}

void Camera::Update(Scene* scene)
{
	GameObject gameObject{ _target, scene };

	_position.x = gameObject.GetComponent<Transform>().position.x
		- Window::GetScaledSize().x / Window::GetM2PRatio();

	_position.y = gameObject.GetComponent<Transform>().position.y
		- Window::GetScaledSize().y / Window::GetM2PRatio();
}

