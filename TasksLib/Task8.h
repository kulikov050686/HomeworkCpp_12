#pragma once
#include <iostream>
#include <memory>
#include "ITask.h"
#include "../TetrisGameLib/TetrisGame.h"

/// <summary>
/// Задача 8
/// </summary>
class Task8 : public ITask
{
public:

	/// <summary>
	/// Конструктор
	/// </summary>
	Task8(std::shared_ptr<TetrisGame> tetrisGame);

	/// <summary>
	/// Запуск
	/// </summary>
	void Run() override;

	/// <summary>
	/// Деструктор
	/// </summary>
	virtual ~Task8() = default;

private:

	/// <summary>
	/// Игра тетрис
	/// </summary>
	std::shared_ptr<TetrisGame> _tetrisGame;
};
