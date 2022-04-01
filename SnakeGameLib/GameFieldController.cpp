#include "pch.h"
#include "GameFieldController.h"

namespace SnakeGameLib
{
	GameFieldController::GameFieldController(std::shared_ptr<IGameField<uint16_t>> field)
	{
		if (field == nullptr) throw "Error!!!";

		_field = field;
		_sizeField = field->GetSize();
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
	}

	void GameFieldController::SetFieldElement(Point2D<uint16_t> point, uint16_t data)
	{
		_field->SetElement(point.x, point.y, data);
	}

	uint16_t GameFieldController::GetFieldElement(Point2D<uint16_t> point)
	{
		return _field->GetElement(point.x, point.y);
	}
}