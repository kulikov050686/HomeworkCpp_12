#include "pch.h"
#include "Game.h"

namespace SnakeGameLib
{
	Game::Game(std::shared_ptr<ControllerLocator> controllerLocator)
	{
		if (controllerLocator == nullptr) throw "Error!!!"; 

		_gameFieldController = controllerLocator->GetGameFieldController();
		if (_gameFieldController == nullptr) throw "Error!!!";

		_snakeController = controllerLocator->GetSnakeController();
		if (_snakeController == nullptr) throw "Error!!!";

		_fruitController = controllerLocator->GetFruitController();
		if (_fruitController == nullptr) throw "Error!!!";
	}

	void Game::Start()
	{		
		Init();
		Print();
	}

	void Game::Print()
	{
		setlocale(LC_ALL, "Russian.utf8");

		Point2D<uint16_t> point{ 0, 0 };
		size_t size = _gameFieldController->GetSizeField();

		for (size_t y = 0; y < size; y++)
		{
			point.y = y;

			for (size_t x = 0; x < size; x++)
			{
				point.x = x;				

				if (_gameFieldController->GetFieldElement(point) == 0) std::cout << " ";
				if (_gameFieldController->GetFieldElement(point) == 1) std::cout << "#";
			}

			std::cout << std::endl;
		}		
	}

	void Game::Init()
	{		
	}

	void Game::AddFruit()
	{
	}
}
