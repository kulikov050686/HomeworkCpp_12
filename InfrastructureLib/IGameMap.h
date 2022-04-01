#pragma once

/// <summary>
/// Интерфейс модели игровой карты
/// </summary>
/// <typeparam name="T"> Тип данных элемента игровой карты </typeparam>
template <typename T>
class IGameMap
{
public:

	/// <summary>
	/// Конструктор
	/// </summary>
	IGameMap() = default;
	
	// <summary>
	/// Получить количество рядов
	/// </summary>	
	virtual size_t GetNumberOfRows() = 0;

	/// <summary>
	/// Получить количество колонок
	/// </summary>	
	virtual size_t GetNumberOfColumns() = 0;

	/// <summary>
	/// Получить данные элемента
	/// </summary>
	/// <param name="row"> Номер ряда </param>
	/// <param name="column"> Номер колонки </param>	
	virtual T GetElement(size_t row, size_t column) = 0;

	/// <summary>
	/// Задать данные элемента
	/// </summary>
	/// <param name="row"> Номер ряда </param>
	/// <param name="column"> Номер столбца </param>
	/// <param name="data"> Данные </param>	
	virtual void SetElement(size_t row, size_t column, T data) = 0;

	/// <summary>
	/// Деструктор
	/// </summary>
	virtual ~IGameMap() = default;

	/// <summary>
	/// Запрет присваивания
	/// </summary>	
	IGameMap& operator = (const IGameMap&) = delete;

	/// <summary>
	/// Запрет копирования
	/// </summary>	
	IGameMap(const IGameMap&) = delete;
};
