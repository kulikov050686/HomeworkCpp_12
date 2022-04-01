#pragma once
#include <locale.h>
#include <memory>

/// <summary>
/// Игра змейка
/// </summary>
class SnakeGame
{
public:
	
	/// <summary>
	/// Конструктор
	/// </summary>
	SnakeGame() = default;

	/// <summary>
	/// Запуск игры
	/// </summary>
	void Run();

	/// <summary>
	/// Деструктор
	/// </summary>
	virtual ~SnakeGame() = default;
};
