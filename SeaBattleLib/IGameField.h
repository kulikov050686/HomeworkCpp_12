#pragma once

/// <summary>
/// Интерфейс модели игрового поля
/// </summary>
/// <typeparam name="T"> Тип данных элемента игрового поля </typeparam>
template <typename T>
class IGameField
{
public:

	/// <summary>
	/// Конструктор
	/// </summary>
	IGameField() = default;

	/// <summary>
	/// Получить размер игрового поля
	/// </summary>	
	virtual size_t GetSize() = 0;

	/// <summary>
	/// Задать элемент игрового поля
	/// </summary>
	/// <typeparam name="T"> Тип элемента игрового поля </typeparam>
	virtual void SetElement(size_t x, size_t y, T element) = 0;

	/// <summary>
	/// Получить элемент игрового поля
	/// </summary>
	/// <typeparam name="T"> Тип элемента игрового поля </typeparam>
	virtual T GetElement(size_t x, size_t y) = 0;

	/// <summary>
	/// Деструктор
	/// </summary>
	virtual ~IGameField() = default;

	/// <summary>
	/// Запрет присваивания
	/// </summary>
	IGameField& operator = (const IGameField&) = delete;

	/// <summary>
	/// Запрет копирования
	/// </summary>	
	IGameField(const IGameField&) = delete;
};

