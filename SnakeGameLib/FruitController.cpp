#include "pch.h"
#include "FruitController.h"

namespace SnakeGameLib
{
	std::shared_ptr<IFruit> FruitController::CreateFruit(Point2D<size_t> coordinates, TypeOfFruit typeOfFruit)
	{
		return std::make_shared<Fruit>(coordinates, typeOfFruit);
	}
}
