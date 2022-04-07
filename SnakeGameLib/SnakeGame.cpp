#include "pch.h"
#include "SnakeGame.h"

namespace SnakeGameLib
{
	void SnakeGame::Run()
	{
		system("cls");
		setlocale(LC_ALL, "Russian.utf8");

		auto controllerLocator = std::make_shared<ControllerLocator>();
		auto game = std::make_shared<Game>(controllerLocator);

		game->Start();
	}
}
