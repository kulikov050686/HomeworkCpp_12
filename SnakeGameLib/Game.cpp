#include "pch.h"
#include "Game.h"

namespace SnakeGameLib
{
	Game::Game(std::shared_ptr<GameFieldController> gameFieldController)
	{
		if (gameFieldController == nullptr) throw "Error!!!";

		_gameFieldController = gameFieldController;
	}

	void Game::Start()
	{
		
	}
}
