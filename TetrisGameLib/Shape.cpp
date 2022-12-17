#include "pch.h"
#include "Shape.h"

namespace TetrisGameLib
{
	Shape::Shape(size_t x, size_t y, ShapeEnum shapeEnum)
	{
		_x = x;
		_y = y;
		_shapeEnum = shapeEnum;

		Init();
	}

	void Shape::MoveDown()
	{
		_y++;
	}

	void Shape::MoveRight()
	{
		_x++;
	}

	void Shape::MoveLeft()
	{
		_x--;
	}

	void Shape::RotateShape()
	{

	}

	std::vector<std::vector<uint16_t>> Shape::GetShape() const
	{		
		return _matrix;
	}
	
	void Shape::Init()
	{
		switch (_shapeEnum)
		{
		case TetrisGameLib::ShapeEnum::FIGURE_1:
			_sizeMatrix = 4;
			_matrix = { {0,0,1,0},
						{0,0,1,0},
						{0,0,1,0},
						{0,0,1,0} };			
			break;
		case TetrisGameLib::ShapeEnum::FIGURE_2:
			_sizeMatrix = 3;
			_matrix = { {0,2,0}, 
						{0,2,2}, 
						{0,0,2} };
			break;
		case TetrisGameLib::ShapeEnum::FIGURE_3:
			_sizeMatrix = 3;
			_matrix = { {0,0,0},
						{3,3,3},
						{0,3,0} };
			break;
		case TetrisGameLib::ShapeEnum::FIGURE_4:
			_sizeMatrix = 3;
			_matrix = { {4,0,0},
						{4,0,0},
						{4,4,0} };
			break;

		case TetrisGameLib::ShapeEnum::FIGURE_5:
			_sizeMatrix = 2;
			_matrix = { {5,5},
						{5,5} };
			break;
		}		
	}
}
