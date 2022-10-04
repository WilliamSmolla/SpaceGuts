#include "pch.h"
#include "PhysicsManager.h"
#include "scene/GameObject.h"
#include "scene/Components.h"

void PhysicsManager::init()
{
	_physicWorld = new b2World(b2Vec2(0, 9.81f));
}

void PhysicsManager::shutdown()
{
	delete _physicWorld;
}

 void PhysicsManager::setRuntimeBodies(entt::registry& registry, Scene* scene)
{
	auto view = registry.view<RigidBody2D>();
	for (auto go : view)
	{
		GameObject gameObject = { go, scene };
		auto& transform = gameObject.GetComponent<Transform>();
		auto& rb2d = gameObject.GetComponent<RigidBody2D>();
		auto& sprite = gameObject.GetComponent<SpriteRenderer>().sprite;

		b2BodyDef bodyDef;
		bodyDef.type = rb2d.type;

		bodyDef.position.Set((transform.position.x), (transform.position.y));
		bodyDef.angle = DEGTORAD(transform.angle);

		b2Body* body = _physicWorld->CreateBody(&bodyDef);
		body->SetFixedRotation(rb2d.fixedRotation);
		rb2d.runtimeBody = body;

		if (gameObject.HasComponent<BoxCollider2D>())
		{
			auto& bc2d = gameObject.GetComponent<BoxCollider2D>();

			b2PolygonShape boxShape;
			
			boxShape.SetAsBox(transform.scale.x / 2.0f, transform.scale.y / 2.0f);

			b2FixtureDef fixtureDef;
			fixtureDef.shape = &boxShape;
			fixtureDef.density = bc2d.density;
			fixtureDef.friction = bc2d.friction;
			fixtureDef.restitution = bc2d.restitution;
			fixtureDef.restitutionThreshold = bc2d.restitutionThreshold;
			body->CreateFixture(&fixtureDef);
		}
	}
}

 void PhysicsManager::setCollisionCallback(b2ContactListener* contactListener)
 {
	 _physicWorld->SetContactListener(contactListener);
 }

 void PhysicsManager::setRuntimeContactCallbacks()
 {
	 for (auto& contactListener : _contactListeners)
	 {
		 _physicWorld->SetContactListener(contactListener);
	 }
 }

void PhysicsManager::update(entt::registry& registry, Scene* scene, float deltaTime)
{
	_physicWorld->Step(deltaTime, _velocityIterations, _positionIterations);
	auto view = registry.view<RigidBody2D>();
	for (auto go : view)
	{
		GameObject gameObject = { go, scene };
		auto& transform = gameObject.GetComponent<Transform>();
		auto& rb2d = gameObject.GetComponent<RigidBody2D>();
		b2Body* body = rb2d.runtimeBody;
		auto& position = body->GetPosition();

		transform.position.x = position.x;
		transform.position.y = position.y;
		transform.angle = RADTODEG(static_cast<double>(body->GetAngle()));
	}
}
