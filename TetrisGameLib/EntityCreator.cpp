#include "pch.h"
#include "EntityCreator.h"

namespace TetrisGameLib
{
	std::shared_ptr<IShape> EntityCreator::CreateShape(size_t x, size_t y, ShapeEnum shapeEnum)
	{
		return std::make_shared<Shape>(x, y, shapeEnum);
	}
}
