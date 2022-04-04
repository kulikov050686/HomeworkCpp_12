#pragma once
#include "IFruit.h"
#include "TypeOfFruit.h"

namespace SnakeGameLib
{
	/// <summary>
	/// Модель фрукт
	/// </summary>
	class Fruit : public IFruit
	{
	public:

		/// <summary>
		/// Конструктор
		/// </summary>
		/// <param name="coordinates"> Координаты фрукта </param>
		/// <param name="typeOfFruit"> Тип фрукта </param>
		Fruit(Point2D<size_t> coordinates, TypeOfFruit typeOfFruit);

		/// <summary>
		/// Получить координаты фрукта
		/// </summary>		
		Point2D<size_t> GetCoordinates() override;

		/// <summary>
		/// Получить тип фрукта
		/// </summary>		
		TypeOfFruit GetTypeOfFruit() override;

		/// <summary>
		/// Деструктор
		/// </summary>
		virtual ~Fruit() = default;

	private:

		/// <summary>
		/// Координаты
		/// </summary>
		Point2D<size_t> _coordinates{ 0,0 };

		/// <summary>
		/// Тип фрукта
		/// </summary>
		TypeOfFruit _typeOfFruit = TypeOfFruit::APPLE;
	};
}
