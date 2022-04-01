#pragma once
#include <locale.h>
#include <memory>

/// <summary>
/// Игра тетрис
/// </summary>
class TetrisGame
{
public:

	/// <summary>
	/// Конструктор
	/// </summary>
	TetrisGame() = default;

	/// <summary>
	/// Запуск игры
	/// </summary>
	void Run();

	/// <summary>
	/// Деструктор
	/// </summary>
	virtual ~TetrisGame() = default;
};

