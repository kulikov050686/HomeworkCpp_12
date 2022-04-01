#pragma once
#include <iostream>
#include "ITask.h"
#include "../MatrixLib/SquareMatrix.h"

/// <summary>
/// Задача 4
/// </summary>
class Task4 : public ITask
{
public:

	/// <summary>
	/// Конструктор
	/// </summary>
	Task4() = default;

	/// <summary>
	/// Запуск
	/// </summary>
	void Run() override;

	/// <summary>
	/// Деструктор
	/// </summary>
	virtual ~Task4() = default;

private:

	/// <summary>
	/// Ввод данных
	/// </summary>
	/// <param name="matrix"> Матрица </param>
	void DataInputInMatrix(Matrix& matrix);

	/// <summary>
	/// Печать матрицы
	/// </summary>
	/// <param name="matrix"> Матрица </param>
	void PrintMatrix(Matrix& matrix);
};
