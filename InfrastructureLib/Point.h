#pragma once

/// <summary>
/// Точка двумерного пространства
/// </summary>
/// <typeparam name="T"> Тип данных координат точки </typeparam>
template <typename T>
struct Point2D
{
	/// <summary>
	/// Координата x
	/// </summary>
	T x;

	/// <summary>
	/// Координата y
	/// </summary>
	T y;
};

/// <summary>
/// Точка трёхмерного пространства
/// </summary>
/// <typeparam name="T"> Тип данных координат точки </typeparam>
template <typename T>
struct Point3D : public Point2D<T>
{
	/// <summary>
	/// Координата z
	/// </summary>
	T z;
};
