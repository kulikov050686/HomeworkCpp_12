#pragma once
#include <iostream>
#include <memory>
#include "ITask.h"
#include "../SnakeGameLib/SnakeGame.h"

/// <summary>
/// Задача 1
/// </summary>
class Task1 : public ITask
{
public:

	/// <summary>
	/// Конструктор
	/// </summary>
	Task1(std::shared_ptr<SnakeGameLib::SnakeGame> snakeGame);

	/// <summary>
	/// Запуск
	/// </summary>
	void Run() override;

	/// <summary>
	/// Деструктор
	/// </summary>
	virtual ~Task1() = default;

private:

	/// <summary>
	/// Игра змейка
	/// </summary>
	std::shared_ptr<SnakeGameLib::SnakeGame> _snakeGame;
};
