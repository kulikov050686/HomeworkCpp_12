#include "pch.h"
#include "Fruit.h"

namespace SnakeGameLib
{
	Fruit::Fruit(Point2D<size_t> coordinates, TypeOfFruit typeOfFruit)
	{
		_coordinates = coordinates;
		_typeOfFruit = typeOfFruit;
	}

	Point2D<size_t> Fruit::GetCoordinates()
	{
		return _coordinates;
	}

	TypeOfFruit Fruit::GetTypeOfFruit()
	{
		return _typeOfFruit;
	}	
}
