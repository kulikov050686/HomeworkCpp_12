#include "pch.h"
#include "SnakeGame.h"
#include "GameFieldController.h"
#include "Game.h"

namespace SnakeGameLib
{
	void SnakeGame::Run()
	{
		system("cls");
		setlocale(LC_ALL, "Russian.utf8");

		auto field = std::make_shared<GameField<uint16_t>>(10);
		auto fieldController = std::make_shared<GameFieldController>(field);
		auto game = std::make_shared<Game>(fieldController);

		game->Start();
	}
}
