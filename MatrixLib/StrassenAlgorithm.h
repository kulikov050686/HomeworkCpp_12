#pragma once
#include "VinohradStrassen.h"
#include "Matrix.h"

class StrassenAlgorithm : public VinohradStrassen
{
private:

    double* _vector_1 = nullptr;
    double* _vector_2 = nullptr;
    size_t _size = 0;
    size_t _columnsMatrixOut = 0;
    size_t _rowsMatrixOut = 0;

    /// <summary>
    /// Проверяет является ли число степенью двойки
    /// </summary>
    /// <param name="number"> Число </param>    
    bool DegreeOfTwo(size_t number);

    /// <summary>
    /// Сравнение матриц
    /// </summary>
    /// <param name="matrix_1"> Первая матрица </param>
    /// <param name="matrix_2"> Вторая матрица </param>    
    bool MatrixComparison(Matrix& matrix_1, Matrix& matrix_2);

    /// <summary>
    /// Проверка на квадратность матрицы и кратность её размера двум
    /// </summary>
    /// <param name="matrix"> Проверяемая матрица </param>    
    bool SquareAndMultiplicityOfTwo(Matrix& matrix);

    /// <summary>
    /// Приведение матрицы к квадратной форме
    /// </summary>
    /// <param name="matrix"> Приводимая матрица </param>    
    Matrix MatrixToSquare(Matrix& matrix);

    /// <summary>
    /// Приведение матрицы к квадратному виду кратному двум
    /// </summary>
    /// <param name="matrix"> Приводимая матрица </param>    
    Matrix MatrixSquareMultipleOfTwo(Matrix& matrix);

    /// <summary>
    /// Линализация матрицы
    /// </summary>
    /// <param name="matrix"> Линализуемая матрица </param>    
    double* Linalization(Matrix& matrix);

    /// <summary>
    /// Алгоритм Винограда - Штрассена
    /// </summary>    
    Matrix Strassen();

public:

	/// <summary>
	/// Умножение матриц методом Винограда - Штрассена
	/// </summary>
	/// <param name="A"> Первая матрица </param>
	/// <param name="B"> Вторая матрица </param>	
	Matrix Multiplication(Matrix& A, Matrix& B);
};
