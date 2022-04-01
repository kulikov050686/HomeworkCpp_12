#include "pch.h"
#include "Task8.h"

Task8::Task8(std::shared_ptr<TetrisGame> tetrisGame)
{
	if (tetrisGame == nullptr) throw "Error!!!";

	_tetrisGame = tetrisGame;
}

void Task8::Run()
{
	_tetrisGame->Run();
}
