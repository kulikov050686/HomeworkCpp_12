#pragma once
#include "../InfrastructureLib/Point.h"

namespace SnakeGameLib
{
	/// <summary>
	/// Элемент змейки
	/// </summary>
	/// <typeparam name="T"> Тип элемента </typeparam>
	template <typename T>
	struct SnakeElement
	{
		/// <summary>
		/// Идентификатор
		/// </summary>
		size_t id;

		/// <summary>
		/// Координаты
		/// </summary>
		Point2D<size_t> coordinates;

		/// <summary>
		/// Элемент
		/// </summary>
		T element;

		/// <summary>
		/// Присваивание
		/// </summary>		
		SnakeElement<T>& operator = (const SnakeElement<T>& obj)
		{
			if (this == &obj) return *this;

			coordinates = obj.coordinates;
			element = obj.element;
			id = obj.id;

			return *this;
		}
	};
}
