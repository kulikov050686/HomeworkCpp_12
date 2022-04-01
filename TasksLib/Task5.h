#pragma once
#include <iostream>
#include <random>
#include "ITask.h"
#include "../MatrixLib/SquareMatrix.h"

/// <summary>
/// Задача 5
/// </summary>
class Task5 : public ITask
{
public:

	/// <summary>
	/// Конструктор
	/// </summary>
	Task5() = default;

	/// <summary>
	/// Запустить
	/// </summary>
	void Run() override;

	/// <summary>
	/// Деструктор
	/// </summary>
	virtual ~Task5() = default;

private:

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

	/// <summary>
	/// Генератор случайных чисел [min, max)
	/// </summary>
	/// <param name="min"> Минимальное значение </param>
	/// <param name="max"> Максимальное значение </param>
	int Random(int min, int max);
};
