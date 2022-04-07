#include "pch.h"
#include "Snake.h"

namespace SnakeGameLib
{
	Snake::Snake(Point2D<size_t> initialCoordinates, uint16_t elementData, size_t numberOfElements)
	{
		if (numberOfElements == 0) throw "Error!!!";

		_numberOfElements = numberOfElements;
		_elementData = elementData;

		_snake[0].id = _lastId;
		_snake[0].coordinates = initialCoordinates;
		_snake[0].element = _elementData;
		_lastId++;

		if (numberOfElements > 1) Init();
	}

	void Snake::SetElement(SnakeElement<uint16_t> element)
	{
		for (auto i = _snake.begin(); i != _snake.end(); i++)
		{
			if (i->coordinates == element.coordinates) return;
		}

		element.id = _lastId;
		_snake.push_back(element);
		_lastId++;
	}

	SnakeElement<uint16_t> Snake::GetElement(size_t itemNumber)
	{
		return _snake[itemNumber];
	}

	void Snake::UpdateElement(SnakeElement<uint16_t> newElement)
	{
		bool key = true;

		for (auto i = _snake.begin(); (i != _snake.end()) && key; i++)
		{
			if (i->id == newElement.id)
			{
				i->coordinates = newElement.coordinates;
				key = !key;
			}
		}
	}	
	
	size_t Snake::GetNumberOfElements()
	{
		return _numberOfElements;
	}

	void Snake::Init()
	{
		for (size_t i = 1; i < _numberOfElements; i++)
		{
			SnakeElement<uint16_t> element;
			element.id = _lastId;
			element.coordinates.x = _snake[0].coordinates.x + i;
			element.coordinates.y = _snake[0].coordinates.y;
			element.element = _elementData;
			
			_snake.push_back(element);
			_lastId++;
		}
	}
}
