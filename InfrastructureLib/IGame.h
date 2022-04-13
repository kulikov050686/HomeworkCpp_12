#pragma once

/// <summary>
/// Интерфейс игра
/// </summary>
class IGame
{
public:

	/// <summary>
	/// Конструктор
	/// </summary>
	IGame() = default;

	/// <summary>
	/// Отрисовать
	/// </summary>
	virtual void Draw() = 0;

	/// <summary>
	/// Деструктор
	/// </summary>
	virtual ~IGame() = default;
};
