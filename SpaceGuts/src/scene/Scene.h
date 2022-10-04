#pragma once
#include "entt/entt.hpp"
#include "core/Window.h"
#include <box2d/b2_world.h>
#include "graphics/Camera.h"

class GameObject;
class b2World;

class Scene
{
public:
	Scene();
	virtual ~Scene() = default;

	GameObject CreateGameObject(); 
	void DestroyGameObject(GameObject gameObject);

	virtual void OnCreate() = 0;
	virtual void HandleEvents(const SDL_Event& event) = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void Render() = 0;
	virtual void OnDestroy() = 0;

protected:
	entt::registry _registry;	
	Camera _camera;

	bool isclicked = false;

	friend class GameObject;
	friend class Renderer;
	friend class PhysicsManager;
	friend class Application;
};
