#pragma once
#include <iostream>
#include <random>
#include <vector>
#include "Menu/MenuController.h"
#include "Convert/Convert.h"
#include "Matrix/SquareMatrix.h"
#include "Matrix/Matrix.h"
#include "Matrix/MatrixOperations.h"

class HomeWork
{
public:

	/// <summary>
	/// Запуск
	/// </summary>
	void Run();

private:

	/// <summary>
	/// Задача №1
	/// </summary>
	void Task1();

	/// <summary>
	/// Задача №2
	/// </summary>
	void Task2();

	/// <summary>
	/// Задача №3
	/// </summary>
	void Task3();

	/// <summary>
	/// Задача №4
	/// </summary>
	void Task4();

	/// <summary>
	/// Задача №5
	/// </summary>
	void Task5();

	/// <summary>
	/// Задача №6
	/// </summary>
	void Task6();

	/// <summary>
	/// Задача №7
	/// </summary>
	void Task7();

	/// <summary>
	/// Задача №8
	/// </summary>
	void Task8();

	/// <summary>
	/// Задача №9
	/// </summary>
	void Task9();

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
	/// Ввод данных в матрицу
	/// </summary>
	/// <param name="matrix"> Матрица </param>
	void DataInputInMatrix(Matrix& matrix);

	/// <summary>
	/// Заполняет матрицу произвольными числами
	/// </summary>
	/// <param name="matrix"> Матрица </param>
	/// <param name="min"> Минимальное число </param>
	/// <param name="max"> Максимальное число </param>
	/// <param name="k"> Коэффициент </param>
	void FillMatrixRandomly(Matrix& matrix, int min, int max, double k = 1);
};
