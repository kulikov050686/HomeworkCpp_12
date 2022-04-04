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
		InitGameField();
	}

	void Game::InitGameField()
	{
		size_t size = _gameFieldController->GetSizeField();
		Point2D<uint16_t> point{ 0,0 };
		uint16_t key = 0;
		size_t i = 0;

		while (key < 4)
		{
			if (key == 0)
			{
				i++;
				point.x = i;

				if (i == size - 1)
				{
					i = 0;
					key++;
				}
			}
			else
			{
				if (key == 1)
				{
					i++;
					point.y = i;

					if (i == size - 1) key++;
				}
				else
				{
					if (key == 2)
					{
						i--;
						point.x = i;

						if (i == 0)
						{
							key++;
							i = size - 1;
						}
					}
					else
					{
						i--;
						point.y = i;

						if (i == 0) key++;
					}
				}
			}

			_gameFieldController->SetFieldElement(point, 1);
		}
	}
}
