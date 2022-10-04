#include "pch.h"
#include "PlayerController.h"
#include "core/InputManager.h"
#include <cmath>
#include "core/Log.h"

void PlayerController::OnCreate() {}

void PlayerController::OnDestroy() {}

void PlayerController::Update(float deltaTime)
{
	auto& rb = GetComponent<RigidBody2D>().runtimeBody;
	auto& transform = GetComponent<Transform>();
	auto& isFlipped = GetComponent<SpriteRenderer>().isFlipped;
	auto& animator = GetComponent<Animator>().controller;
	auto& collider = GetComponent<BoxCollider2D>();

	auto velocity = rb->GetLinearVelocity();

	if (isGrounded)
	{
		Log::Trace("player is grounded");
	}
	else
	{
		Log::Trace("player is not grounded");
	}

	if (InputManager::IsKeyDown(Keycode::A) && isGrounded)
	{
	    rb->ApplyForceToCenter(b2Vec2(-45.0f, velocity.y), true);

		isFlipped = true;
	}
	else if (InputManager::IsKeyDown(Keycode::D) && isGrounded)
	{
		rb->ApplyForceToCenter(b2Vec2(45.0f, velocity.y), true);

		isFlipped = false;
	}

	if (InputManager::IsKeyDown(Keycode::W) && isReleased && isGrounded)
	{
		isReleased = false;

		b2Vec2 vel = rb->GetLinearVelocity();
		vel.y = 20;
		rb->SetLinearVelocity(vel);
	}
	else if(!InputManager::IsKeyDown(Keycode::W) && !isReleased)
	{
		isReleased = true;
	}

	auto abs_speed = std::abs(rb->GetLinearVelocity().x);

	if (abs_speed >= 3.0f && abs_speed > 0.5f && isGrounded)
	{
		GetComponent<Animator>().controller.SetAnimationState("Run");
	}
	else if (abs_speed < 3.0f && abs_speed > 0.5f && isGrounded)
	{
		GetComponent<Animator>().controller.SetAnimationState("Walk");
	}
	else if (abs_speed >= 0 && abs_speed <= 0.5f && isGrounded)
	{
		GetComponent<Animator>().controller.SetAnimationState("Idle");
	}

	if (!isGrounded)
	{
		GetComponent<Animator>().controller.SetAnimationState("Jump");
	}

	if (rb->GetLinearVelocity().x > 5 || rb->GetLinearVelocity().x < -5)
	{
		if (isFlipped)
		{
			rb->SetLinearVelocity(b2Vec2(-5.0f, 0.0f));
		}
		else
		{
			rb->SetLinearVelocity(b2Vec2(5.0f, 0.0f));
		}
	}
}
