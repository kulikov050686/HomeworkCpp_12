#pragma once
#include "Matrix.h"
#include "StrassenAlgorithm.h"

class MatrixOperations
{
public:

	/// <summary>
	/// Проверяет возможность сложения или вычитания матриц
	/// </summary>
	/// <param name="matrix_1"> Первая матрица </param>
	/// <param name="matrix_2"> Вторая матрица </param>	
	static bool AddAndSubResolution(Matrix& matrix_1, Matrix& matrix_2);

	/// <summary>
	/// Проверяет возможность умножения матриц
	/// </summary>
	/// <param name="matrix_1"> Превая матрица </param>
	/// <param name="matrix_2"> Вторая матрица </param>	
	static bool MultResolution(Matrix& matrix_1, Matrix& matrix_2);

	/// <summary>
	/// Сумма двух матриц
	/// </summary>
	/// <param name="matrix_1"> Первая матрица </param>
	/// <param name="matrix_2"> Вторая матрица </param>	
	static Matrix Addition(Matrix& matrix_1, Matrix& matrix_2);

	/// <summary>
	/// Разность двух матриц
	/// </summary>
	/// <param name="matrix_1"> Первая матрица </param>
	/// <param name="matrix_2"> Вторая матрица </param>	
	static Matrix Subtraction(Matrix& matrix_1, Matrix& matrix_2);

	/// <summary>
	/// Произведение двух матриц
	/// </summary>
	/// <param name="matrix_1"> Первая матрица </param>
	/// <param name="matrix_2"> Вторая матрица </param>	
	static Matrix Multiplication(Matrix& matrix_1, Matrix& matrix_2);

	/// <summary>
	/// Перемножение матриц алгоритмом Винограда-Штрассена
	/// </summary>
	/// <param name="matrix_1"> Первая матрица </param>
	/// <param name="matrix_2"> Вторая матрица </param>
	static Matrix MultiplicationVinohradStrassen(Matrix& matrix_1, Matrix& matrix_2);
};
