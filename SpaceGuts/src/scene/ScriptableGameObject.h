#pragma once
#include "scene/GameObject.h"
#include "Components.h"

class ScriptableGameObject
{
public:
	virtual ~ScriptableGameObject() {}

	template<typename T>
	T& GetComponent()
	{
		return gameObject.GetComponent<T>();
	}

	GameObject gameObject;


protected:
	virtual void OnCreate() {}
	virtual void OnDestroy() {}
	virtual void Update(float deltaTime) {}

private:
	friend class Scene;
	friend class TestScene;
};


