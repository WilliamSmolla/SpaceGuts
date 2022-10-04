#pragma once
#include "scene/Scene.h"

class TestScene : public Scene
{
public:
	TestScene();
	~TestScene();

	virtual void OnCreate() override;
	virtual void HandleEvents(const SDL_Event& event) override;
	virtual void Update(float deltaTime) override;
	virtual void Render() override;
	virtual void OnDestroy() override;
};

