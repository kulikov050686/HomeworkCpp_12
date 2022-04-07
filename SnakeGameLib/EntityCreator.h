#pragma once
#include <memory>
#include "../InfrastructureLib/Point.h"
#include "IFruit.h"
#include "ISnake.h"
#include "TypeOfFruit.h"
#include "Fruit.h"
#include "Snake.h"

namespace SnakeGameLib
{
	/// <summary>
	/// Создатель сущностей
	/// </summary>
	class EntityCreator
	{
	public:

		/// <summary>
		/// Конструктор
		/// </summary>
		EntityCreator() = default;
		
		/// <summary>
		/// Создать фрукт
		/// </summary>
		/// <param name="coordinates"> Координаты фрукта </param>
		/// <param name="typeOfFruit"> Тип фрукта </param>		
		std::shared_ptr<IFruit> CreateFruit(Point2D<size_t> coordinates, TypeOfFruit typeOfFruit);

		/// <summary>
		/// Создать змейку
		/// </summary>
		/// <param name="initialCoordinates"> Начальные координаты </param>
		/// <param name="elementData"> Данные элемента змейки </param>
		/// <param name="numberOfElements"> Количество элементов змейки </param>		
		std::shared_ptr<ISnake<uint16_t>> CreateSnake(Point2D<size_t> initialCoordinates,
													  uint16_t elementData,
													  size_t numberOfElements = 4);

		/// <summary>
		/// Деструктор
		/// </summary>
		virtual ~EntityCreator() = default;
	};
}
