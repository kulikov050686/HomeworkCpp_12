#include "pch.h"
#include "Task1.h"

Task1::Task1(std::shared_ptr<SnakeGameLib::SnakeGame> snakeGame)
{
	if (snakeGame == nullptr) throw "Error!!";

	_snakeGame = snakeGame;
}

void Task1::Run()
{
	_snakeGame->Run();
}
