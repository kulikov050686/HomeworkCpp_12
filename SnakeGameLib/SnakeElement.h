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
	};
}
