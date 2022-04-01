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

	/// <summary>
	/// Присваивание
	/// </summary>	
	Point2D<T>& operator = (const Point2D<T>& obj)
	{
		if (this == &obj) return *this;
		
		x = obj.x;
		y = obj.y;

		return *this;
	}

	/// <summary>
	/// Сравнения
	/// </summary>	
	bool operator == (const Point2D<T>& obj)
	{
		if (this == &obj) return true;		
		if ((x == obj.x) && (y == obj.y)) return true;

		return false;
	}

	/// <summary>
	/// Обратное сравнение
	/// </summary>	
	bool operator != (const Point2D<T>& obj)
	{
		return !(*this == obj);
	}

	/// <summary>
	/// Сложение
	/// </summary>	
	Point2D<T>& operator + (const Point2D<T>& obj)
	{
		x += obj.x;
		y += obj.y;

		return *this;
	}

	/// <summary>
	/// Вычитание
	/// </summary>	
	Point2D<T>& operator - (const Point2D<T>& obj)
	{
		x -= obj.x;
		y -= obj.y;

		return *this;
	}

	/// <summary>
	/// Инкремент версия постфикс
	/// </summary>
	Point2D<T>& operator ++ (int)
	{
		x++;
		y++;

		return *this;
	}

	/// <summary>
	/// Инкремент версия префикс
	/// </summary>
	Point2D<T>& operator ++ ()
	{
		++x;
		++y;

		return *this;
	}

	/// <summary>
	/// Декримент версия постфикс
	/// </summary>	
	Point2D<T> operator -- (int)
	{
		x--;
		y--;

		return *this;
	}

	/// <summary>
	/// Декримент версия префикс
	/// </summary>
	Point2D<T> operator -- ()
	{
		--x;
		--y;

		return *this;
	}
};

 /// <summary>
 /// Точка трёхмерного пространства
 /// </summary>
 /// <typeparam name="T"> Тип данных координат точки </typeparam>
template <typename T>
struct Point3D
{
	/// <summary>
	/// Координата x
	/// </summary>
	T x;

	/// <summary>
	/// Координата y
	/// </summary>
	T y;

	/// <summary>
	/// Координата z
	/// </summary>
	T z;

	/// <summary>
	/// Присваивание
	/// </summary>	
	Point3D<T>& operator = (const Point3D<T>& obj)
	{
		if (this == &obj) return *this;

		x = obj.x;
		y = obj.y;
		z = obj.z;

		return *this;
	}

	/// <summary>
	/// Сравнение
	/// </summary>	
	bool operator == (const Point3D<T>& obj)
	{
		if (this == &obj) return true;
		if ((x == obj.x) && (y == obj.y) && (z == obj.z)) return true;

		return false;
	}

	/// <summary>
	/// Обратное сравнение
	/// </summary>	
	bool operator != (const Point3D<T>& obj)
	{
		return !(*this == obj);
	}

	/// <summary>
	/// Сложение
	/// </summary>	
	Point3D<T> operator + (const Point3D<T>& obj)
	{
		x += obj.x;
		y += obj.y;
		z += obj.z;

		return *this;
	}

	/// <summary>
	/// Вычитание
	/// </summary>	
	Point3D<T>& operator - (const Point3D<T>& obj)
	{
		x -= obj.x;
		y -= obj.y;
		z -= obj.z;

		return *this;
	}

	/// <summary>
	/// Инкремент версия постфикс
	/// </summary>
	Point3D<T>& operator ++ (int)
	{
		x++;
		y++;
		z++;

		return *this;
	}

	/// <summary>
	/// Инкремент версия префикс
	/// </summary>
	Point3D<T>& operator ++ ()
	{
		++x;
		++y;
		++z;

		return *this;
	}

	/// <summary>
	/// Декримент версия постфикс
	/// </summary>	
	Point3D<T> operator -- (int)
	{
		x--;
		y--;
		z--;

		return *this;
	}

	/// <summary>
	/// Декримент версия префикс
	/// </summary>
	Point3D<T> operator -- ()
	{
		--x;
		--y;
		--z;

		return *this;
	}
};
