#include "pch.h"
#include "Snake.h"

namespace SnakeGameLib
{
	Snake::Snake(Point2D<size_t> initialCoordinates, uint16_t elementData, size_t numberOfElements)
	{
		if (numberOfElements == 0) throw "Error!!!";

		_elementData = elementData;
		_snake.resize(numberOfElements);

		_snake[0].id = _lastId;
		_snake[0].coordinates = initialCoordinates;
		_snake[0].element = _elementData;
		_lastId++;

		if (numberOfElements > 1) Init();
	}

	void Snake::SetElement()
	{
		SnakeElement<uint16_t> element;

		element.id = _lastId;
		element.coordinates.x = 0;
		element.coordinates.y = 0;
		element.element = _elementData;

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
		return _snake.size();
	}

	void Snake::Init()
	{
		for (size_t i = 1; i < _snake.size(); i++)
		{
			SnakeElement<uint16_t> element;
			element.id = _lastId;
			element.coordinates.x = _snake[0].coordinates.x + i;
			element.coordinates.y = _snake[0].coordinates.y;
			element.element = _elementData;

			_snake[i] = element;
			_lastId++;
		}
	}
}
