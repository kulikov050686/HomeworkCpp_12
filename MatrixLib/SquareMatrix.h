#pragma once
#include "Matrix.h"

class SquareMatrix : public Matrix
{
private:

	/// <summary>
	/// Количество перестановок
	/// </summary>
	size_t _numberOfPermutations = 0;

	/// <summary>
	/// Размер квадратной матрицы
	/// </summary>
	size_t _size = 0;

public:

	/// <summary>
	/// Конструктор квадратной матрицы
	/// </summary>
	/// <param name="size"> Размер матрицы </param>
	SquareMatrix(size_t size);

	/// <summary>
	/// Приводит квадратную матрицу к треугольному виду
	/// </summary>
	size_t Triangulation();

	/// <summary>
	/// Проверка на диагональность
	/// </summary>	
	bool IsDiagonal();

	/// <summary>
	/// Проверка на треугольность
	/// </summary>	
	bool IsTriangle();

	/// <summary>
	/// Детерминант квадратной матрицы
	/// </summary>	
	double Determinant();

	/// <summary>
	/// Транспонирование
	/// </summary>
	void Transpose();	
};
