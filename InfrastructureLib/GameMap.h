#pragma once
#include <vector>
#include "IGameMap.h"

/// <summary>
/// Модель игровой карты
/// </summary>
/// <typeparam name="T"> Тип данных элемента игровой карты </typeparam>
template <typename T>
class GameMap : public IGameMap<T>
{
public:

	/// <summary>
	/// Конструктор
	/// </summary>
	/// <param name="numberOfColumns"> Количество колонок </param>
	/// <param name="numberOfRows"> Количество рядов </param>
	GameMap(size_t numberOfColumns, size_t numberOfRows);
	
	// <summary>
	/// Получить количество рядов
	/// </summary>	
	size_t GetNumberOfRows() override;

	/// <summary>
	/// Получить количество колонок
	/// </summary>	
	size_t GetNumberOfColumns() override;

	/// <summary>
	/// Получить данные элемента
	/// </summary>
	/// <param name="row"> Номер ряда </param>
	/// <param name="column"> Номер колонки </param>	
	T GetElement(size_t row, size_t column) override;

	/// <summary>
	/// Задать данные элемента
	/// </summary>
	/// <param name="row"> Номер ряда </param>
	/// <param name="column"> Номер столбца </param>
	/// <param name="data"> Данные </param>	
	void SetElement(size_t row, size_t column, T data) override;

	/// <summary>
	/// Деструктор
	/// </summary>
	virtual ~GameMap() = default;

public:

	/// <summary>
	/// Количество колонок
	/// </summary>
	size_t _numberOfColumns = 0;

	/// <summary>
	/// Количество рядов
	/// </summary>
	size_t _numberOfRows = 0;

	/// <summary>
	/// Игровое карта
	/// </summary>
	std::vector<std::vector<T>> _gameMap;

	/// <summary>
	/// Инициализация
	/// </summary>
	void Init();
};
