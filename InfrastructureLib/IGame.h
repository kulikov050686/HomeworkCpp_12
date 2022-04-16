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
	/// Отрисовка
	/// </summary>
	virtual void Draw() = 0;

	/// <summary>
	/// Обработка событий таймера
	/// </summary>
	/// <param name="value"> Параметр </param>
	virtual void Timer(int value) = 0;

	/// <summary>
	/// Обработка событий изменения размеров окна
	/// </summary>
	/// <param name="width"> Ширина окна </param>
	/// <param name="height"> Высота окна </param>
	virtual void Reshape(int width, int height) = 0;

	/// <summary>
	/// Обработка событий клавиатуры
	/// </summary>
	/// <param name="key"> Код клавиши </param>
	/// <param name="x"> Координата x мыши </param>
	/// <param name="y"> Координата y мыши </param>
	virtual void Keyboard(unsigned char key, int x, int y) = 0;

	/// <summary>
	/// Обработка событий времени бездействия
	/// </summary>
	virtual void Idel() = 0;

	/// <summary>
	/// Деструктор
	/// </summary>
	virtual ~IGame() = default;
};
