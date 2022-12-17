#pragma once
#include <memory>
#include "IShape.h"
#include "Shape.h"
#include "ShapeEnum.h"

namespace TetrisGameLib
{
	/// <summary>
	/// ��������� ���������
	/// </summary>
	class EntityCreator
	{
	public:

		/// <summary>
		/// ������� ������
		/// </summary>
		/// <param name="x"> ���������� x </param>
		/// <param name="y"> ���������� y </param>	
		/// <param name="shapeEnum"> ����� ������ </param>	
		std::shared_ptr<IShape> CreateShape(size_t x, size_t y, ShapeEnum shapeEnum);
	};
}
