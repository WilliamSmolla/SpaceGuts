#pragma once
#include "pch.h"
#include "maths/Maths.h"
#include "graphics/Texture.h"
#include "utils/Timer.h"
#include "graphics/AnimationController.h"
#include <box2d/b2_body.h>

struct Tag
{
	std::string tag;
	unsigned int layer;
};

struct Layer
{
	int layer;
};

struct Transform
{
	Vec2 position = Vec2(0.0f, 0.0f);
	Vec2 scale = Vec2(1.0f, 1.0f);
	double angle = 0;
};

struct SpriteRenderer
{
	std::shared_ptr<Texture> sprite;
	bool isFlipped = false;
};

struct Animator
{
	AnimationController controller;
};

class ScriptableGameObject;
struct Script
{
	ScriptableGameObject* instance = nullptr;

	ScriptableGameObject* (*InstantiateScript)();
	void (*DestroyScript)(Script*);

	template<typename T>
	void Bind()
	{
		InstantiateScript = []() { return static_cast<ScriptableGameObject*>(new T()); };
		DestroyScript = [](Script* script) { delete script->instance; script->instance = nullptr; };
	}
};

struct RigidBody2D
{
	b2BodyType type = b2BodyType::b2_staticBody;
	bool fixedRotation = false; 

	b2Body* runtimeBody = nullptr;
};

struct BoxCollider2D
{
	Vec2 offset = Vec2(0.0f, 0.0f);
	Vec2 size = Vec2(0.5f, 0.5f);

	float density = 1.0f;
	float friction = 0.9f;
	float restitution = 0.5f;
	float restitutionThreshold = 0.5f;

	b2Fixture* runtimeFixture = nullptr;
};



