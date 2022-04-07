#include "pch.h"
#include "GameFieldController.h"

namespace SnakeGameLib
{
	GameFieldController::GameFieldController(std::shared_ptr<IGameField<uint16_t>> field)
	{
		if (field == nullptr) throw "Error!!!";

		_field = field;
		_sizeField = field->GetSize();

		InitField();
	}

	uint16_t GameFieldController::GetSizeField()
	{
		return _field->GetSize();
	}

	void GameFieldController::ClearField()
	{
		setlocale(LC_ALL, "Russian.utf8");				

		for (size_t y = 1; y < _sizeField - 1; y++)
		{
			for (size_t x = 1; x < _sizeField - 1; x++)
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

	bool GameFieldController::AddSnakeOnField(std::shared_ptr<ISnake<uint16_t>> snake)
	{
		if (snake == nullptr) throw "Error!!!";

		bool key = true;

		for (size_t i = 0; (i < snake->GetNumberOfElements()) && key; i++)
		{
			size_t x = snake->GetElement(i).coordinates.x;
			size_t y = snake->GetElement(i).coordinates.y;
			uint16_t snakeElement = snake->GetElement(i).element;

			key = key && BelongingToPointOfGameArea(snake->GetElement(i).coordinates);

			if(key) _field->SetElement(x, y, snakeElement);
		}

		return key;
	}
	
	bool GameFieldController::AddFruitOnField(std::shared_ptr<IFruit> fruit)
	{
		if (fruit == nullptr) throw "Error!!!";

		if (BelongingToPointOfGameArea(fruit->GetCoordinates()))
		{
			switch (fruit->GetTypeOfFruit())
			{
				case TypeOfFruit::APPLE:
				{
					break;
				}			
				
				case TypeOfFruit::PEACH:
				{
					break;
				}				

				case TypeOfFruit::PEAR:
				{
					break;
				}

				default: return false;				
			}
			
			return true;
		}
		
		return false;
	}

	bool GameFieldController::BelongingToPointOfGameArea(Point2D<size_t> point)
	{
		return (0 < point.x) && (point.x < _sizeField - 1) && (0 < point.y) && (point.y < _sizeField - 1);
	}

	void GameFieldController::InitField()
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

				if (i == _sizeField - 1)
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

					if (i == _sizeField - 1) key++;
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
							i = _sizeField - 1;
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

			_field->SetElement(point.x, point.y, 1);
		}
	}	
}