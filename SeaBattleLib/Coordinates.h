#pragma once

/// <summary>
/// Координаты
/// </summary>
/// <typeparam name="T"> Тип данных координат </typeparam>
template <typename T>
struct Coordinates
{
	/// <summary>
	/// Координаты начала
	/// </summary>
	T beginning;

	/// <summary>
	/// Координаты конца
	/// </summary>
	T end;
};
