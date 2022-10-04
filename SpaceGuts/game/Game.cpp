#include "pch.h"
#include "Game.h"
#include "TestScene.h"

Game::Game()
	: Application()
{
	ResourceManager::LoadResource("assets/textures/player/player.png");
	ResourceManager::LoadResource("assets/textures/floor.png");

	SceneManager::AddScene("TestScene", std::make_shared<TestScene>());
}

Game::~Game()
{
}

void Game::HandleEvents(const SDL_Event& event)
{
	SceneManager::CurrentScene()->HandleEvents(event);
}

void Game::Update(float deltaTime)
{
	SceneManager::CurrentScene()->Update(deltaTime);
}

void Game::Render()
{
	SceneManager::CurrentScene()->Render();
}
