#pragma once
#include "scene/Scene.h"

class SceneManager
{
public:
	static SceneManager& GetInstance()
	{
		static SceneManager instance;
		return instance;
	}

	SceneManager(SceneManager const&) = delete;
	void operator=(SceneManager const&) = delete;

	static void Init() { GetInstance().init(); }
	static void Shutdown() { GetInstance().shutdown(); }
	static void AddScene(std::string name, std::shared_ptr<Scene> scene) { GetInstance().addScene(name, scene); }
	static void RemoveScene(std::string name) { GetInstance().removeScene(name); }
	static void LoadScene(std::string name) { GetInstance().loadScene(name); }
	static void Update(float deltaTime) { GetInstance().update(deltaTime); }
	static std::shared_ptr<Scene> CurrentScene() { return GetInstance().currentScene(); }

private:
	SceneManager(){}

	void init();
	void shutdown();
	void addScene(std::string name, std::shared_ptr<Scene> scene);
	void removeScene(std::string name);
	void loadScene(std::string name);
	void update(float deltaTime);
	std::shared_ptr<Scene> currentScene() { return _currentScene; }

	std::unordered_map<std::string, std::shared_ptr<Scene>> _scenes;
	std::shared_ptr<Scene> _currentScene = nullptr;
};

