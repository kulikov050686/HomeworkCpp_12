#include "pch.h"
#include "Task5.h"

void Task5::Run()
{
	system("cls");
	setlocale(LC_ALL, "Russian.utf8");

	SquareMatrix matrix(4);
	FillMatrixRandomly(matrix, 0, 10);
	PrintMatrix(matrix);

	for (int i = 0; i < matrix.GetNumberOfRows(); i++)
	{
		for (int j = 0; j < matrix.GetNumberOfColumns(); j++)
		{
			if (i != j)
			{
				matrix.SetElement(i, j, 0);
			}
		}
	}

	PrintMatrix(matrix);
}

void Task5::PrintMatrix(Matrix& matrix)
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

void Task5::FillMatrixRandomly(Matrix& matrix, int min, int max, double k)
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

int Task5::Random(int min, int max)
{
	// Генерируем случайное число
	std::random_device rd;

	// Инициализируем Вихрь Мерсенна случайным стартовым числом 
	std::mt19937 mersenne(rd());

	return min + mersenne() % (max - min);
}
