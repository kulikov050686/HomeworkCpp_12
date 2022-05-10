#include "pch.h"
#include "GameMapController.h"

namespace TetrisGameLib
{
	GameMapController::GameMapController(std::shared_ptr<IGameMap<uint16_t>> map)
	{
		if (map == nullptr) throw "Error!!!";

		_map = map;
		_mapColumns = _map->GetNumberOfColumns();
		_mapRows = _map->GetNumberOfRows();

		InitMap();
	}

	size_t GameMapController::GetNumberOfRows()
	{
		return _map->GetNumberOfRows();
	}

	size_t GameMapController::GetNumberOfColumns()
	{
		return _map->GetNumberOfColumns();
	}

	void GameMapController::ClearField()
	{
		for (size_t x = 1; x < _mapColumns - 1; x++)
		{
			for (size_t y = 1; y < _mapRows - 1; y++)
			{
				_map->SetElement(y, x, 0);
			}
		}
	}

	uint16_t GameMapController::GetFieldElement(Point2D<uint16_t> point)
	{
		return _map->GetElement(point.y, point.x);
	}

	void GameMapController::InitMap()
	{
		Point2D<uint16_t> point{ 0,0 };
		uint16_t key = 0;
		size_t i = 0;

		while (key < 4)
		{
			if (key == 0)
			{
				i++;
				point.x = i;

				if (i == _mapColumns - 1)
				{
					i = 0;
					key++;
				}
			}
			else
			{
				if (key == 1)
				{
					i++;
					point.y = i;

					if (i == _mapRows - 1) key++;
				}
				else
				{
					if (key == 2)
					{
						i--;
						point.x = i;

						if (i == 0)
						{
							key++;
							i = _mapColumns - 1;
						}
					}
					else
					{
						i--;
						point.y = i;

						if (i == 0) key++;
					}
				}
			}

			_map->SetElement(point.y, point.x, 1);
		}
	}
}
