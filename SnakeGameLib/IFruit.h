#pragma once
#include "../InfrastructureLib/Point.h"
#include "TypeOfFruit.h"

namespace SnakeGameLib
{
	/// <summary>
	/// Интерфейс модели фрукт
	/// </summary>
	class IFruit
	{
	public:

		/// <summary>
		/// Конструктор
		/// </summary>
		IFruit() = default;

		/// <summary>
		/// Получить координаты фрукта
		/// </summary>		
		virtual Point2D<size_t> GetCoordinates() = 0;

		/// <summary>
		/// Получить тип фрукта
		/// </summary>		
		virtual TypeOfFruit GetTypeOfFruit() = 0;

		/// <summary>
		/// Деструктор
		/// </summary>
		virtual ~IFruit() = default;

		/// <summary>
		/// Запрет присваивания
		/// </summary>		
		IFruit& operator = (const IFruit&) = delete;

		/// <summary>
		/// Запрет копироваия
		/// </summary>		
		IFruit(const IFruit&) = delete;
	};
}
