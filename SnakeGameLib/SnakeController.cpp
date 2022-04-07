#include "pch.h"
#include "SnakeController.h"

namespace SnakeGameLib
{
	std::shared_ptr<ISnake<uint16_t>> SnakeController::CreateSnake(Point2D<size_t> initialCoordinates, 
																   uint16_t elementData, 
														           size_t numberOfElements)
	{
		return std::make_shared<Snake>(initialCoordinates, elementData, numberOfElements);		
	}
}