#pragma once
#include <iostream>
#include <random>
#include "ITask.h"
#include "../MatrixLib/SquareMatrix.h"
#include "../MatrixLib/MatrixOperations.h"

/// <summary>
/// Задача 6
/// </summary>
class Task6 : public ITask
{
public:

	/// <summary>
	/// Конструктор
	/// </summary>
	Task6() = default;

	/// <summary>
	/// Запустить
	/// </summary>
	void Run() override;

	/// <summary>
	/// Деструктор
	/// </summary>
	virtual ~Task6() = default;

private:

	/// <summary>
	/// Генератор случайных чисел [min, max)
	/// </summary>
	/// <param name="min"> Минимальное значение </param>
	/// <param name="max"> Максимальное значение </param>	
	int Random(int min, int max);

	/// <summary>
	/// Печать матрицы
	/// </summary>
	/// <param name="matrix"> Матрица </param>
	void PrintMatrix(Matrix& matrix);

	/// <summary>
	/// Заполняет матрицу произвольными числами
	/// </summary>
	/// <param name="matrix"> Матрица </param>
	/// <param name="min"> Минимальное число </param>
	/// <param name="max"> Максимальное число </param>
	/// <param name="k"> Коэффициент </param>
	void FillMatrixRandomly(Matrix& matrix, int min, int max, double k = 1);
};
