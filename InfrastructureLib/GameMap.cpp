#include "pch.h"
#include "GameMap.h"

template<typename T>
GameMap<T>::GameMap(size_t numberOfColumns, size_t numberOfRows)
{
	if (numberOfColumns == 0 || numberOfRows == 0) throw "Error!!!";

	_numberOfColumns = numberOfColumns;
	_numberOfRows = numberOfRows;

	Init();
}

template<typename T>
size_t GameMap<T>::GetNumberOfRows()
{
	return _numberOfRows;
}

template<typename T>
size_t GameMap<T>::GetNumberOfColumns()
{
	return _numberOfColumns;
}

template<typename T>
T GameMap<T>::GetElement(size_t row, size_t column)
{
	return _gameMap[row][column];
}

template<typename T>
void GameMap<T>::SetElement(size_t row, size_t column, T data)
{
	_gameMap[row][column] = data;
}

template<typename T>
void GameMap<T>::Init()
{
	_gameMap.resize(_numberOfRows);

	for (size_t i = 0; i < _numberOfRows; i++)
	{
		_gameMap[i].resize(_numberOfColumns);
	}
}
