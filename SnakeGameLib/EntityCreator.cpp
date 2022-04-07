#include "pch.h"
#include "EntityCreator.h"

namespace SnakeGameLib
{
	std::shared_ptr<IFruit> EntityCreator::CreateFruit(Point2D<size_t> coordinates, TypeOfFruit typeOfFruit)
	{
		return std::make_shared<Fruit>(coordinates, typeOfFruit);
	}

	std::shared_ptr<ISnake<uint16_t>> EntityCreator::CreateSnake(Point2D<size_t> initialCoordinates, 
																 uint16_t elementData, 
																 size_t numberOfElements)
	{
		return std::make_shared<Snake>(initialCoordinates, elementData, numberOfElements);
	}
}
