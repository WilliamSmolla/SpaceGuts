#include "pch.h"
#include "Scene.h"
#include "GameObject.h"
#include "Components.h"
#include "core/InputManager.h"
#include "scene/ScriptableGameObject.h"
#include "core/ResourceManager.h"
#include "graphics/Renderer.h"
#include "physics/PhysicsManager.h"
#include "../game/scripts/PlayerController.h"

Scene::Scene()
{	

}

GameObject Scene::CreateGameObject()
{
	GameObject gameObject = GameObject(_registry.create(), this);
	return gameObject;
}

void Scene::DestroyGameObject(GameObject gameObject)
{
	_registry.destroy(gameObject);
}


