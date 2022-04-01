#include "pch.h"
#include "Ship.h"

namespace SeaBattleLib
{
	Ship::Ship(Point2D<uint16_t> shipCoordinate)
	{
		CreateShip();
		CreateShipCoordinate(shipCoordinate);
	}

	Ship::Ship(Point2D<uint16_t> shipCoordinate, uint16_t numberOfDecks, Direction direction)
	{
		if (numberOfDecks == 0) throw "Error!!!";

		_numberOfDecks = numberOfDecks;
		_direction = direction;

		if ((direction == Direction::LEFT) || (direction == Direction::RIGHT))
		{
			_placement = Placement::HORIZONTALLY;
		}

		if ((direction == Direction::DOWN) || (direction == Direction::UP))
		{
			_placement = Placement::VERTICALLY;
		}

		CreateShip();
		CreateShipCoordinate(shipCoordinate);
	}

	Placement Ship::GetPlacement()
	{
		return _placement;
	}

	uint16_t Ship::GetNumberOfDecks()
	{
		return _numberOfDecks;
	}

	Coordinates<Point2D<int16_t>> Ship::GetLocationCoordinates()
	{
		return _shipCoordinate;
	}

	uint16_t Ship::GetShipDeck(uint16_t number)
	{
		if (number > _numberOfDecks) throw "Error!!!";

		return _ship[number];
	}

	bool Ship::GetPointBelongingToShip(Point2D<uint16_t> point)
	{
		return (_shipCoordinate.beginning.x <= point.x) &&
			(point.x <= _shipCoordinate.end.x) &&
			(_shipCoordinate.beginning.y <= point.y) &&
			(point.y <= _shipCoordinate.end.y);
	}

	ResultOfShot Ship::AttackOnShip(Point2D<uint16_t> point)
	{
		if ((_numberOfHits < _numberOfDecks) && GetPointBelongingToShip(point))
		{
			_numberOfHits++;

			if (_numberOfHits == _numberOfDecks) return ResultOfShot::KILLED;

			return ResultOfShot::WOUNDED;
		}

		return ResultOfShot::MISSED;
	}

	uint16_t Ship::GetNumberOfHits()
	{
		return _numberOfHits;
	}

	void Ship::CreateShip()
	{
		if (_numberOfDecks == 1)
		{
			_ship = { 1 };
			return;
		}

		if (_numberOfDecks == 2)
		{
			_ship = { 2, 2 };
			return;
		}

		if (_numberOfDecks == 3)
		{
			_ship = { 3, 3, 3 };
			return;
		}

		if (_numberOfDecks == 4)
		{
			_ship = { 4, 4, 4, 4 };
			return;
		}
	}

	void Ship::CreateShipCoordinate(Point2D<uint16_t> shipCoordinate)
	{
		_shipCoordinate.beginning.x = shipCoordinate.x;
		_shipCoordinate.beginning.y = shipCoordinate.y;
		_shipCoordinate.end.x = shipCoordinate.x;
		_shipCoordinate.end.y = shipCoordinate.y;

		if (_numberOfDecks > 1)
		{
			if (_direction == Direction::LEFT)
			{
				_shipCoordinate.beginning.x++;
				_shipCoordinate.beginning.x -= _numberOfDecks;
			}

			if (_direction == Direction::UP)
			{
				_shipCoordinate.beginning.y++;
				_shipCoordinate.beginning.y -= _numberOfDecks;
			}

			if (_direction == Direction::RIGHT)
			{
				_shipCoordinate.end.x--;
				_shipCoordinate.end.x += _numberOfDecks;
			}

			if (_direction == Direction::DOWN)
			{
				_shipCoordinate.end.y--;
				_shipCoordinate.end.y += _numberOfDecks;
			}
		}
	}
}
