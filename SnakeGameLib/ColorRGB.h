#pragma once

namespace SnakeGameLib
{
	/// <summary>
	/// Цвета
	/// </summary>
	/// <typeparam name="T"> Тип данных цвета </typeparam>
	template <typename T>
	struct ColorRGB
	{
		/// <summary>
		/// Красный
		/// </summary>
		T r;

		/// <summary>
		/// Злёный
		/// </summary>
		T g;

		/// <summary>
		/// Синий
		/// </summary>
		T b;
	};
}