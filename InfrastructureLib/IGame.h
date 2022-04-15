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
	/// Таймер
	/// </summary>
	/// <param name="value"></param>
	virtual void Timer(int value) = 0;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="width"></param>
	/// <param name="height"></param>
	virtual void Reshape(int width, int height) = 0;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="key"></param>
	/// <param name="x"></param>
	/// <param name="y"></param>
	virtual void Keyboard(unsigned char key, int x, int y) = 0;

	/// <summary>
	/// 
	/// </summary>
	virtual void Idel() = 0;

	/// <summary>
	/// Деструктор
	/// </summary>
	virtual ~IGame() = default;
};
