#include "pch.h"
#include "Task6.h"

void Task6::Run()
{
	system("cls");
	setlocale(LC_ALL, "Russian.utf8");

	Matrix matrix_1(1, 4);
	SquareMatrix matrix_2(4);

	if (MatrixOperations::MultResolution(matrix_1, matrix_2))
	{
		FillMatrixRandomly(matrix_1, 1, 10);
		PrintMatrix(matrix_1);

		FillMatrixRandomly(matrix_2, 1, 10);
		PrintMatrix(matrix_2);

		Matrix matrixResult = MatrixOperations::Multiplication(matrix_1, matrix_2);

		PrintMatrix(matrixResult);
	}
}

int Task6::Random(int min, int max)
{
	// Генерируем случайное число
	std::random_device rd;

	// Инициализируем Вихрь Мерсенна случайным стартовым числом 
	std::mt19937 mersenne(rd());

	return min + mersenne() % (max - min);
}

void Task6::PrintMatrix(Matrix& matrix)
{
	for (int i = 0; i < matrix.GetNumberOfRows(); i++)
	{
		std::cout << "| ";

		for (int j = 0; j < matrix.GetNumberOfColumns(); j++)
		{
			std::cout << matrix.GetElement(i, j) << " ";
		}

		std::cout << "|" << std::endl;
	}

	std::cout << std::endl;
}

void Task6::FillMatrixRandomly(Matrix& matrix, int min, int max, double k)
{
	double data = 0;

	for (int i = 0; i < matrix.GetNumberOfRows(); i++)
	{
		for (int j = 0; j < matrix.GetNumberOfColumns(); j++)
		{
			data = k * Random(min, max);
			matrix.SetElement(i, j, data);
		}
	}
}
