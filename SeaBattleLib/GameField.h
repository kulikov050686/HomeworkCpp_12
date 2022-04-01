#pragma once
#include <vector>
#include "IGameField.h"

/// <summary>
/// Модель игрового поля
/// </summary>
/// <typeparam name="T"> Тип данных элемента игрового поля </typeparam>
template <typename T>
class GameField : public IGameField<T>
{
public:

	/// <summary>
	/// Конструктор
	/// </summary>
	/// <param name="size"> Размер игрового поля </param>
	GameField(size_t size);

	/// <summary>
	/// Получить размер игрового поля
	/// </summary>	
	size_t GetSize();

	/// <summary>
	/// Задать элемент игрового поля
	/// </summary>
	/// <typeparam name="T"> Тип элемента игрового поля </typeparam>
	void SetElement(size_t x, size_t y, T element);

	/// <summary>
	/// Получить элемент игрового поля
	/// </summary>
	/// <typeparam name="T"> Тип элемента игрового поля </typeparam>
	T GetElement(size_t x, size_t y);

	/// <summary>
	/// Деструктор
	/// </summary>
	virtual ~GameField() = default;	

private:

	/// <summary>
	/// Размер игровог поля
	/// </summary>
	size_t _size = 0;

	/// <summary>
	/// Игровое поле
	/// </summary>
	std::vector<std::vector<T>> _gameField;

	/// <summary>
	/// Инициализация поля
	/// </summary>
	void Init();
};
