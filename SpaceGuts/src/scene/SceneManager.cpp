#include "pch.h"
#include "SceneManager.h"
#include "core/Log.h"

void SceneManager::init()
{
}

void SceneManager::shutdown()
{
}

void SceneManager::addScene(std::string name, std::shared_ptr<Scene> scene)
{
	_scenes[name] = scene;

	if (_currentScene == nullptr)
	{
		_currentScene = _scenes[name];
		_currentScene->OnCreate();
	}
}

void SceneManager::removeScene(std::string name)
{
	if (_scenes[name] == nullptr)
	{
		Log::Error("Cannot remove " + name + "from the scene list. It does not exist.");
		return;
	}

	if (_currentScene = _scenes[name])
	{
		_currentScene = nullptr;
	}

	_currentScene->OnDestroy();
	_scenes.erase(name);
}

void SceneManager::loadScene(std::string name)
{
	if (_scenes[name] == nullptr)
	{
		Log::Error("Cannot load " + name + "from the scene list. It does not exist.");
		return;
	}

	_currentScene->OnDestroy();
	_currentScene = _scenes[name];
}

void SceneManager::update(float deltaTime)
{
	if (_currentScene != nullptr)
	{
		_currentScene->Update(deltaTime);
	}
}
