#include "pch.h"
#include "SnakeGame.h"

namespace SnakeGameLib
{
	void SnakeGame::Run()
	{
		system("cls");
		setlocale(LC_ALL, "Russian.utf8");

		auto field = std::make_shared<GameField<uint16_t>>(10);
	}
}
