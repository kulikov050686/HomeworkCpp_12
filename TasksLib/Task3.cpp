#include "pch.h"
#include "Task3.h"

void Task3::Run()
{
	system("cls");
	setlocale(LC_ALL, "Russian.utf8");

	std::string strNumber;
	int number;

	std::cout << "Введите размер матрицы (1 - 10): ";
	std::cin >> strNumber;

	if (Convert::ToInt(strNumber, number))
	{
		if (0 < number && number < 11)
		{
			SquareMatrix matrix(number);
			bool key = true;
			int k = 0;

			for (int i = 0; i < matrix.GetNumberOfRows(); i++)
			{
				for (int j = 0; (j < matrix.GetNumberOfColumns()) && key; j++)
				{
					matrix.SetElement(i, j, k);
					k++;
				}

				for (int j = matrix.GetNumberOfColumns() - 1; (j >= 0) && !key; j--)
				{
					matrix.SetElement(i, j, k);
					k++;
				}

				key = !key;
			}

			PrintMatrix(matrix);
		}
		else
		{
			std::cout << "Неверно введённые данные!!!" << std::endl;
		}
	}
	else
	{
		std::cout << "Неверно введённые данные!!!" << std::endl;
	}
}

void Task3::PrintMatrix(Matrix& matrix)
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
