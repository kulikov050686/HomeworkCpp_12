#pragma once
#include <memory>
#include "ISnake.h"
#include "Snake.h"

namespace SnakeGameLib
{
	/// <summary>
	/// Контроллер змейки
	/// </summary>
	class SnakeController
	{
	public:

		/// <summary>
		/// Конструктор
		/// </summary>
		SnakeController() = default;
		
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
		virtual ~SnakeController() = default;
	};
}
