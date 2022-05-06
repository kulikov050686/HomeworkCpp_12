#include "pch.h"
#include "Game.h"

namespace TetrisGameLib
{
	Game::Game(std::shared_ptr<ControllerLocator> controllerLocator)
	{
		if (controllerLocator == nullptr) throw "Error!!!";

		_gameMapController = controllerLocator->GetGameMapController();
		if(_gameMapController == nullptr) throw "Error!!!";
	}

	void Game::Draw()
	{
	}

	void Game::Timer(int value)
	{
	}

	void Game::Reshape(int width, int height)
	{
	}

	void Game::Keyboard(unsigned char key, int x, int y)
	{
	}

	void Game::Idel()
	{
	}
}