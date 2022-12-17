#pragma once
#include <memory>
#include "IShape.h"
#include "Shape.h"
#include "ShapeEnum.h"

namespace TetrisGameLib
{
	/// <summary>
	/// Создатель сущностей
	/// </summary>
	class EntityCreator
	{
	public:

		/// <summary>
		/// Создать фигуру
		/// </summary>
		/// <param name="x"> Координата x </param>
		/// <param name="y"> Координата y </param>	
		/// <param name="shapeEnum"> Форма фигуры </param>	
		std::shared_ptr<IShape> CreateShape(size_t x, size_t y, ShapeEnum shapeEnum);
	};
}
