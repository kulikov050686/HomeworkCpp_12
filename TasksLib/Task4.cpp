#include "pch.h"
#include "Task4.h"

void Task4::Run()
{
	system("cls");
	setlocale(LC_ALL, "Russian.utf8");

	SquareMatrix matrix_1(4);
	SquareMatrix matrix_2(4);

	DataInputInMatrix(matrix_1);
	PrintMatrix(matrix_1);

	DataInputInMatrix(matrix_2);
	PrintMatrix(matrix_2);

	if (matrix_1 == matrix_2)
	{
		std::cout << "Матрицы равны!!!" << std::endl;
	}
	else
	{
		std::cout << "Матрицы не равны!!!" << std::endl;
	}
}

void Task4::DataInputInMatrix(Matrix& matrix)
{
	double data = 0;

	for (int i = 0; i < matrix.GetNumberOfRows(); i++)
	{
		for (int j = 0; j < matrix.GetNumberOfColumns(); j++)
		{
			std::cout << "a[" << i << "," << j << "]= ";
			std::cin >> data;
			matrix.SetElement(i, j, data);
		}
	}
}

void Task4::PrintMatrix(Matrix& matrix)
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
