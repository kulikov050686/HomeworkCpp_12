#pragma once
#include <iostream>
#include"ITask.h"
#include "../ConvertLib/Convert.h"
#include "../MatrixLib/SquareMatrix.h"

/// <summary>
/// Задача 3
/// </summary>
class Task3 : public ITask
{
public:

	/// <summary>
	/// Конструктор
	/// </summary>
	Task3() = default;

	/// <summary>
	/// Запуск
	/// </summary>
	void Run() override;

	/// <summary>
	/// Деструктор
	/// </summary>
	virtual ~Task3() = default;

private:

	/// <summary>
	/// Печать матрицы
	/// </summary>
	/// <param name="matrix"> Матрица </param>
	void PrintMatrix(Matrix& matrix);
};

