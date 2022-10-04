#include "pch.h"
#include "TestScene.h"
#include "scene/GameObject.h"
#include "scene/Components.h"
#include "core/InputManager.h"
#include "scene/ScriptableGameObject.h"
#include "core/ResourceManager.h"
#include "graphics/Renderer.h"
#include "physics/PhysicsManager.h"
#include "../game/scripts/PlayerController.h"

TestScene::TestScene()
{
}

TestScene::~TestScene()
{
}

void TestScene::OnCreate()
{
	GameObject _box = CreateGameObject();
	auto& boxTag = _box.AddComponent<Tag>();
	auto& boxTransform = _box.AddComponent<Transform>();
	auto& boxSpriteRenderer = _box.AddComponent<SpriteRenderer>();
	auto& boxBoxCollider = _box.AddComponent<BoxCollider2D>();
	auto& boxRigidBody = _box.AddComponent<RigidBody2D>();

	boxTag.layer = 3;
	boxTag.tag = "box";
	boxTransform.position = Vec2(1.0f, -5);
	boxTransform.scale = Vec2(1.0f, 1.0f);
	boxSpriteRenderer.sprite = ResourceManager::GetResource<TextureResource>("floor")->texture;
	boxSpriteRenderer.isFlipped = false;
	boxRigidBody.type = b2BodyType::b2_dynamicBody;
	boxTransform.angle = 0.0f;
	boxBoxCollider.friction = 0.8f;

	GameObject _floor = CreateGameObject();
	auto& floorTag = _floor.AddComponent<Tag>();
	auto& floorTransform = _floor.AddComponent<Transform>();
	auto& floorSpriteRenderer = _floor.AddComponent<SpriteRenderer>();
	auto& floorBoxCollider = _floor.AddComponent<BoxCollider2D>();
	auto& floorRigidBody = _floor.AddComponent<RigidBody2D>();

	floorTag.layer = 2;
	floorTag.tag = "floor";
	floorTransform.position = Vec2(0.0f, 8.0f);
	floorTransform.scale = Vec2(22.0f, 1.0f);
	floorSpriteRenderer.sprite = ResourceManager::GetResource<TextureResource>("floor")->texture;
	floorSpriteRenderer.isFlipped = false;

	GameObject _rightWall = CreateGameObject();
	auto& rightWallTag = _rightWall.AddComponent<Tag>();
	auto& rightWallTransform = _rightWall.AddComponent<Transform>();
	auto& rightWallSpriteRenderer = _rightWall.AddComponent<SpriteRenderer>();
	auto& rightWallBoxCollider = _rightWall.AddComponent<BoxCollider2D>();
	auto& rightWallRigidBody = _rightWall.AddComponent<RigidBody2D>();

	rightWallTag.layer = 2;
	rightWallTag.tag = "floor";
	rightWallTransform.position = Vec2(8.0f, 10.0f);
	rightWallTransform.angle = 90;
	rightWallTransform.scale = Vec2(22.0f, 1.0f);
	rightWallSpriteRenderer.sprite = ResourceManager::GetResource<TextureResource>("floor")->texture;
	rightWallSpriteRenderer.isFlipped = false;

	GameObject _leftWall = CreateGameObject();
	auto& leftWallTag = _leftWall.AddComponent<Tag>();
	auto& leftWallTransform = _leftWall.AddComponent<Transform>();
	auto& leftWallSpriteRenderer = _leftWall.AddComponent<SpriteRenderer>();
	auto& leftWallBoxCollider = _leftWall.AddComponent<BoxCollider2D>();
	auto& leftWallRigidBody = _leftWall.AddComponent<RigidBody2D>();

	leftWallTag.layer = 2;
	leftWallTag.tag = "floor";
	leftWallTransform.position = Vec2(-8.0f, 10.0f);
	leftWallTransform.angle = -90;
	leftWallTransform.scale = Vec2(22.0f, 1.0f);
	leftWallSpriteRenderer.sprite = ResourceManager::GetResource<TextureResource>("floor")->texture;
	leftWallSpriteRenderer.isFlipped = false;

	GameObject _player = CreateGameObject();
	auto& tag = _player.AddComponent<Tag>();
	auto& transform = _player.AddComponent<Transform>();
	auto& spriteRenderer = _player.AddComponent<SpriteRenderer>();
	auto& animator = _player.AddComponent<Animator>();
	auto& boxCollider = _player.AddComponent<BoxCollider2D>();
	auto& rigidBody = _player.AddComponent<RigidBody2D>();
	auto& script = _player.AddComponent<Script>();

	script.Bind<PlayerController>();
	tag.layer = 1;
	tag.tag = "player";
	transform.position = Vec2(2.0f, -2.5f);
	transform.scale = Vec2(2.0f, 2.0f);
	spriteRenderer.sprite = ResourceManager::GetResource<TextureResource>("player")->texture;
	spriteRenderer.isFlipped = true;
	rigidBody.type = b2BodyType::b2_dynamicBody;
	rigidBody.fixedRotation = true;
	boxCollider.friction = 0.8f;

	std::shared_ptr<AnimationClip> idleAnimation = std::make_shared<AnimationClip>();
	std::shared_ptr<AnimationClip> walkingAnimation = std::make_shared<AnimationClip>();
	std::shared_ptr<AnimationClip> runningAnimation = std::make_shared<AnimationClip>();
	std::shared_ptr<AnimationClip> jumpingAnimation = std::make_shared<AnimationClip>();

	idleAnimation->AddFrame(0 * 64, 0 * 64, 64, 64, 75);
	idleAnimation->AddFrame(1 * 64, 0 * 64, 64, 64, 75);
	idleAnimation->AddFrame(2 * 64, 0 * 64, 64, 64, 75);
	idleAnimation->AddFrame(3 * 64, 0 * 64, 64, 64, 75);
	idleAnimation->AddFrame(2 * 64, 0 * 64, 64, 64, 75);
	idleAnimation->AddFrame(1 * 64, 0 * 64, 64, 64, 75);
	idleAnimation->SetIsLooped(true);

	walkingAnimation->AddFrame(0 * 64, 4 * 64, 64, 64, 75);
	walkingAnimation->AddFrame(1 * 64, 4 * 64, 64, 64, 75);
	walkingAnimation->AddFrame(2 * 64, 4 * 64, 64, 64, 75);
	walkingAnimation->AddFrame(3 * 64, 4 * 64, 64, 64, 75);
	walkingAnimation->AddFrame(4 * 64, 4 * 64, 64, 64, 75);
	walkingAnimation->AddFrame(5 * 64, 4 * 64, 64, 64, 75);
	walkingAnimation->AddFrame(6 * 64, 4 * 64, 64, 64, 75);
	walkingAnimation->AddFrame(7 * 64, 4 * 64, 64, 64, 75);
	walkingAnimation->SetIsLooped(true);

	runningAnimation->AddFrame(4 * 64, 0 * 64, 64, 64, 75);
	runningAnimation->AddFrame(5 * 64, 0 * 64, 64, 64, 75);
	runningAnimation->AddFrame(6 * 64, 0 * 64, 64, 64, 75);
	runningAnimation->AddFrame(7 * 64, 0 * 64, 64, 64, 75);
	runningAnimation->AddFrame(0, 1 * 64, 64, 64, 75);
	runningAnimation->AddFrame(1 * 64, 1 * 64, 64, 64, 75);
	runningAnimation->AddFrame(2 * 64, 1 * 64, 64, 64, 75);
	runningAnimation->AddFrame(3 * 64, 1 * 64, 64, 64, 75);
	runningAnimation->SetIsLooped(true);

	jumpingAnimation->AddFrame(3 * 64, 5 * 64, 64, 64, 75);
	jumpingAnimation->AddFrame(4 * 64, 5 * 64, 64, 64, 75);
	jumpingAnimation->AddFrame(5 * 64, 5 * 64, 64, 64, 75);
	jumpingAnimation->AddFrame(6 * 64, 5 * 64, 64, 64, 75);
	jumpingAnimation->AddFrame(7 * 64, 5 * 64, 64, 64, 75);
	jumpingAnimation->SetIsLooped(false);

	animator.controller.AddAnimation("Idle", idleAnimation);
	animator.controller.AddAnimation("Walk", walkingAnimation);
	animator.controller.AddAnimation("Run", runningAnimation);
	animator.controller.AddAnimation("Jump", jumpingAnimation);

	_camera.SetTarget(_player);

	PhysicsManager::SetRuntimeBodies(_registry, this);
}

void TestScene::HandleEvents(const SDL_Event& event)
{
	InputManager::UpdateInputs(event);
}

void TestScene::Update(float deltaTime)
{
	// update scripts
	_registry.view<Script>().each([=](auto gameObject, auto& script)
		{
			if (!script.instance)
			{
				script.instance = script.InstantiateScript();
				script.instance->gameObject = GameObject{ gameObject, this };
				script.instance->OnCreate();
			}

			script.instance->Update(deltaTime);
		});

	// update camera 
	_camera.Update(this);

	if (InputManager::IsKeyDown(Keycode::R) && !isclicked)
	{
		isclicked = true;
		auto animatorView = _registry.view<Tag>();
		for (auto& go : animatorView)
		{
			GameObject gameObject = { go, this };

			if (gameObject.GetComponent<Tag>().tag == "box")
			{
				//gameObject.GetComponent<Transform>().position = b2Vec2(0.0f, -10);
				//const b2Vec2 vec = b2Vec2(0.0f, -10);
				gameObject.GetComponent<RigidBody2D>().runtimeBody->SetTransform(b2Vec2(0.0f, -5), 0);
				gameObject.GetComponent<RigidBody2D>().runtimeBody->SetLinearVelocity(b2Vec2(0.0f, -2.0f));
			}
		}
	}
	else if (!InputManager::IsKeyDown(Keycode::W) && isclicked)
	{
		isclicked = false;
	}

	// update physics
	PhysicsManager::Update(_registry, this, 1.0f / 60.0f);

	// update animators
	auto animatorView = _registry.view<Animator>();
	for (auto& gameObject : animatorView)
	{
		auto& controller = animatorView.get<Animator>(gameObject).controller;
		controller.Update(deltaTime);
	}
}

void TestScene::Render()
{
	Renderer::RenderClear(Vec4(180, 234, 170, 255));
	Renderer::Render(_registry, this);
	Renderer::RenderPresent();
}

void TestScene::OnDestroy()
{
	_registry.clear();
}
