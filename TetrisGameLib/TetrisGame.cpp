#include "pch.h"
#include "TetrisGame.h"

namespace TetrisGameLib
{
	TetrisGame::TetrisGame(std::shared_ptr<IGame> game)
	{
	}

	void TetrisGame::Run()
	{
		system("cls");
		setlocale(LC_ALL, "Russian.utf8");
	}
}
