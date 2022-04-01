#include "pch.h"
#include "GameFieldController.h"

namespace SeaBattleLib
{
	GameFieldController::GameFieldController(std::shared_ptr<IGameField<uint16_t>> field)
	{
		if (field == nullptr) throw "Error!!!";
		if (field->GetSize() == 0) throw "Error!!!";

		_field = field;
		_sizeField = field->GetSize();
	}

	bool GameFieldController::AddShipOnField(std::shared_ptr<IShip> ship)
	{
		if (ship == nullptr) throw "Error!!!";

		if (CheckingBoundaries(ship) && CollisionChecking(ship))
		{
			uint16_t xmin = ship->GetLocationCoordinates().beginning.x;
			uint16_t ymin = ship->GetLocationCoordinates().beginning.y;
			uint16_t xmax = ship->GetLocationCoordinates().end.x;
			uint16_t ymax = ship->GetLocationCoordinates().end.y;
			Placement placement = ship->GetPlacement();

			if (ship->GetNumberOfDecks() == 1)
			{
				_field->SetElement(xmin, ymin, ship->GetShipDeck(0));
				_listShips.push_back(ship);
				return true;
			}

			for (size_t x = xmin; (x <= xmax) && (placement == Placement::HORIZONTALLY); x++)
			{
				_field->SetElement(x, ymin, ship->GetShipDeck(x - xmin));
			}

			for (size_t y = ymin; (y <= ymax) && (placement == Placement::VERTICALLY); y++)
			{
				_field->SetElement(xmin, y, ship->GetShipDeck(y - ymin));
			}

			_listShips.push_back(ship);
			return true;
		}

		return false;
	}

	bool GameFieldController::CheckingBoundaries(std::shared_ptr<IShip> ship)
	{
		return (ship->GetLocationCoordinates().beginning.x >= 0) &&
			(ship->GetLocationCoordinates().beginning.y >= 0) &&
			(ship->GetLocationCoordinates().end.x < _sizeField) &&
			(ship->GetLocationCoordinates().end.y < _sizeField);
	}

	uint16_t GameFieldController::GetSizeField()
	{
		return _field->GetSize();
	}

	void GameFieldController::ClearField()
	{
		for (size_t x = 0; x < _sizeField; x++)
		{
			for (size_t y = 0; y < _sizeField; y++)
			{
				_field->SetElement(x, y, 0);
			}
		}

		_listShips.clear();
	}

	void GameFieldController::SetFieldElement(Point2D<uint16_t> point, uint16_t data)
	{
		_field->SetElement(point.x, point.y, data);
	}

	uint16_t GameFieldController::GetFieldElement(Point2D<uint16_t> point)
	{
		return _field->GetElement(point.x, point.y);
	}

	ResultOfShot GameFieldController::ShootAtShip(Point2D<uint16_t> pointOfShot)
	{
		if (_field->GetElement(pointOfShot.x, pointOfShot.y) == 1)
		{
			return ResultOfAttack(pointOfShot, 1);
		}

		if (_field->GetElement(pointOfShot.x, pointOfShot.y) == 2)
		{
			return ResultOfAttack(pointOfShot, 2);
		}

		if (_field->GetElement(pointOfShot.x, pointOfShot.y) == 3)
		{
			return ResultOfAttack(pointOfShot, 3);
		}

		if (_field->GetElement(pointOfShot.x, pointOfShot.y) == 4)
		{
			return ResultOfAttack(pointOfShot, 4);
		}

		return ResultOfShot::MISSED;
	}

	size_t GameFieldController::NumberOfShipsOnField()
	{
		return _listShips.size();
	}

	bool GameFieldController::NoShipsOnField()
	{
		return _listShips.empty();
	}

	Coordinates<Point2D<int16_t>> GameFieldController::GetCoordinatesOfSunkenShip()
	{
		return _coordinatesOfSunkenShip;
	}

	ResultOfShot GameFieldController::ResultOfAttack(Point2D<uint16_t> point, uint16_t numberOfDecks)
	{
		ResultOfShot result = ResultOfShot::MISSED;
		std::list<std::shared_ptr<IShip>>::iterator i;
		bool key = true;

		for (auto iterator = _listShips.begin(); (iterator != _listShips.end()) && key; iterator++)
		{
			if ((*iterator)->GetNumberOfDecks() == numberOfDecks)
			{
				result = (*iterator)->AttackOnShip(point);

				if (result != ResultOfShot::MISSED) key = !key;
				if (result == ResultOfShot::KILLED) i = iterator;
			}
		}

		if (result == ResultOfShot::KILLED)
		{
			_coordinatesOfSunkenShip.beginning.x = (*i)->GetLocationCoordinates().beginning.x;
			_coordinatesOfSunkenShip.beginning.y = (*i)->GetLocationCoordinates().beginning.y;
			_coordinatesOfSunkenShip.end.x = (*i)->GetLocationCoordinates().end.x;
			_coordinatesOfSunkenShip.end.y = (*i)->GetLocationCoordinates().end.y;

			_listShips.erase(i);
		}

		return result;
	}

	bool GameFieldController::CollisionChecking(std::shared_ptr<IShip> ship)
	{
		int16_t minX = ship->GetLocationCoordinates().beginning.x - 1;
		int16_t minY = ship->GetLocationCoordinates().beginning.y - 1;
		int16_t maxX = ship->GetLocationCoordinates().end.x + 1;
		int16_t maxY = ship->GetLocationCoordinates().end.y + 1;
		bool key = true;

		if (minX < 0) minX = 0;
		if (maxX == _sizeField) maxX = _sizeField - 1;
		if (minY < 0) minY = 0;
		if (maxY == _sizeField) maxY = _sizeField - 1;

		for (size_t x = minX; (x <= maxX) && key; x++)
		{
			for (size_t y = minY; (y <= maxY) && key; y++)
			{
				key = key && (_field->GetElement(x, y) == 0);
			}
		}

		return key;
	}
}
