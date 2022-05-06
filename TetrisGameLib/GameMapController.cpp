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
	}

	void GameMapController::ClearField()
	{
		for (size_t x = 0; x < _map->GetNumberOfColumns(); x++)
		{
			for (size_t y = 0; y < _map->GetNumberOfRows(); y++)
			{
				_map->SetElement(y, x, 0);
			}
		}
	}

	void GameMapController::InitMap()
	{
	}
}