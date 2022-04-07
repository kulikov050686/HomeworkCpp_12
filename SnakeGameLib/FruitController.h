#pragma once
#include <memory>
#include "Fruit.h"
#include "../InfrastructureLib/Point.h"
#include "TypeOfFruit.h"

namespace SnakeGameLib
{
	/// <summary>
	/// Контроллер фрукта
	/// </summary>
	class FruitController
	{
	public:
		
		/// <summary>
		/// Конструктор
		/// </summary>
		FruitController() = default;

		/// <summary>
		/// Создать фрукт
		/// </summary>
		/// <param name="coordinates"> Координаты фрукта </param>
		/// <param name="typeOfFruit"> Тип фрукта </param>		
		std::shared_ptr<IFruit> CreateFruit(Point2D<size_t> coordinates, TypeOfFruit typeOfFruit);

		/// <summary>
		/// Деструктор
		/// </summary>
		virtual ~FruitController() = default;

	private:

		/// <summary>
		/// Запрет копирования
		/// </summary>		
		FruitController(const FruitController&) = delete;

		/// <summary>
		/// Запрет присваивания
		/// </summary>		
		FruitController& operator = (const FruitController&) = delete;
	};
}
