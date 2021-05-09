#include "HomeWork.h"

void HomeWork::Run()
{
	system("cls");
	setlocale(LC_ALL, "Russian.utf8");

	bool exit = false;
	std::string text = "Выберите пункт меню";
	std::vector<std::string> item = { "Задача 1",
									  "Задача 2",
									  "Задача 3",
		                              "Задача 4",
		                              "Задача 5", 
		                              "Задача 6",
									  "Выход" };

	MenuController menu(item);



	while (!exit)
	{
		switch (menu.selectedMenuItem(text))
		{
		case 0:
			Task1();
			break;
		case 1:
			Task2();
			break;
		case 2:
			Task3();
			break;
		case 3:
			Task4();
			break;
		case 4:
			Task5();
			break;
		case 5:
			Task6();
			break;
		case 6:
			exit = true;
			break;
		}

		_getch();
	}
}

void HomeWork::Task1()
{	
}

void HomeWork::Task2()
{
}

void HomeWork::Task3()
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

void HomeWork::Task4()
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

void HomeWork::Task5()
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

void HomeWork::Task6()
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

int HomeWork::Random(int min, int max)
{
	// Генерируем случайное число
	std::random_device rd;

	// Инициализируем Вихрь Мерсенна случайным стартовым числом 
	std::mt19937 mersenne(rd());

	return min + mersenne() % (max - min);
}

void HomeWork::PrintMatrix(Matrix& matrix)
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

void HomeWork::DataInputInMatrix(Matrix& matrix)
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

void HomeWork::FillMatrixRandomly(Matrix& matrix, int min, int max, double k)
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
