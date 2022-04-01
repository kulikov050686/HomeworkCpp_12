#include "pch.h"
#include "GameField.h"

template<typename T>
GameField<T>::GameField(size_t size)
{
	if (size == 0) throw "Error!!!";
	_size = size;

	Init();
}

template<typename T>
size_t GameField<T>::GetSize()
{
	return _size;
}

template<typename T>
void GameField<T>::SetElement(size_t x, size_t y, T element)
{
	if(x >= _size || y >= _size) throw "Error!!!";

	_gameField[y][x] = element;
}

template<typename T>
T GameField<T>::GetElement(size_t x, size_t y)
{
	if (x >= _size || y >= _size) throw "Error!!!";

	return _gameField[y][x];
}

template<typename T>
void GameField<T>::Init()
{
	_gameField.resize(_size);

	for (size_t i = 0; i < _size; i++)
	{
		_gameField[i].resize(_size);		
	}
}
