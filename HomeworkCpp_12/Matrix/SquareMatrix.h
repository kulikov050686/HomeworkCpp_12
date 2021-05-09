#pragma once
#include "Matrix.h"

class SquareMatrix : public Matrix
{
private:

	/// <summary>
	/// Количество перестановок
	/// </summary>
	int numberOfPermutations = 0;

	/// <summary>
	/// Размер квадратной матрицы
	/// </summary>
	int size = 0;

public:

	/// <summary>
	/// Конструктор квадратной матрицы
	/// </summary>
	/// <param name="size"> Размер матрицы </param>
	SquareMatrix(int size);

	/// <summary>
	/// Приводит квадратную матрицу к треугольному виду
	/// </summary>
	int Triangulation();

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
