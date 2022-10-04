#include "pch.h"
#include "CollisionCallback.h"
#include "core/Log.h"

PlayerGroundedCallback::PlayerGroundedCallback()
	: b2ContactListener{}{}

PlayerGroundedCallback::~PlayerGroundedCallback(){}

void PlayerGroundedCallback::BeginContact(b2Contact* contact)
{
	Log::Trace("contact started");
}

void PlayerGroundedCallback::EndContact(b2Contact* contact)
{
}
