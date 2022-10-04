#pragma once
#include "core/Application.h"

class Game : public Application
{
public:
	Game();
	~Game();

	virtual void HandleEvents(const SDL_Event& event) override;
	virtual void Update(float deltaTime) override;
	virtual void Render() override;
};

