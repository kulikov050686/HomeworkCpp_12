#include "pch.h"
#include "ShipController.h"

namespace SeaBattleLib
{
	std::shared_ptr<IShip> ShipController::CreateShip(Point2D<uint16_t> shipCoordinate)
	{
		return std::make_shared<Ship>(shipCoordinate);
	}

	std::shared_ptr<IShip> ShipController::CreateShip(Point2D<uint16_t> shipCoordinate,
		uint16_t numberOfDecks,
		Direction direction)
	{
		if (numberOfDecks == 0) throw "Error!!!";

		return std::make_shared<Ship>(shipCoordinate, numberOfDecks, direction);
	}
}
