#pragma once
#include "entt/entt.hpp"
#include "scene/Scene.h"
#include "box2d/b2_world.h"
#include "box2d/b2_body.h"
#include "box2d/b2_fixture.h"
#include "box2d/b2_polygon_shape.h"
#include "box2d/b2_circle_shape.h"

class PhysicsManager
{
public:
	static PhysicsManager& GetInstance()
	{
		static PhysicsManager instance;
		return instance;
	}

	PhysicsManager(PhysicsManager const&) = delete;
	void operator=(PhysicsManager const&) = delete;

	static void Init() { GetInstance().init(); }
	static void Shutdown() { GetInstance().shutdown(); }
	static void SetRuntimeBodies(entt::registry& registry, Scene* scene) 
		{GetInstance().setRuntimeBodies(registry, scene); }
	static void Update(entt::registry& registry, Scene* scene, float deltaTime) 
		{ GetInstance().update(registry, scene, deltaTime); }
	static void SetCollisionCallback(b2ContactListener* contactListener)
	{ GetInstance().setCollisionCallback(contactListener); }

	static b2World* GetPhysicWorld() { return GetInstance().getPhysicWorld(); }

private:
	PhysicsManager(){}

	void init();
	void shutdown();
	void setRuntimeBodies(entt::registry& registry, Scene* scene);
	void setCollisionCallback(b2ContactListener* contactListener);
	void setRuntimeContactCallbacks();
	void update(entt::registry& registry, Scene* scene, float deltaTime);
	b2World* getPhysicWorld() const { return _physicWorld; }

	b2World* _physicWorld = nullptr;
	int _velocityIterations = 6;
	int _positionIterations = 2;

	std::vector<b2ContactListener*> _contactListeners;
	unsigned int _listenerInsertId = 0;
};

