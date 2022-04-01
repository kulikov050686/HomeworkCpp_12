#include "pch.h"
#include "Task7.h"

void Task7::Run()
{
	system("cls");
	setlocale(LC_ALL, "Russian.utf8");
	
	bool exit = false;

	Init();
	Print();

	do
	{
		std::string strBeginningX = "";
		std::string strBeginningY = "";
		std::string strEndX = "";
		std::string strEndY = "";
		bool key1 = false;
		bool key2 = false;

		do
		{
			std::cout << "Введите координаты начала региона (через пробел): ";
			std::cin >> strBeginningX >> strBeginningY;

			key1 = Convert::ToUlonglong(strBeginningX, _beginningX) && _beginningX < _size;
			key2 = Convert::ToUlonglong(strBeginningY, _beginningY) && _beginningY < _size;

			if (!(key1 && key2)) std::cout << "Ошибка ввода данных!!!" << std::endl;

		} while (!(key1 && key2));

		do
		{
			std::cout << "Введите координаты конца региона (через пробел): ";
			std::cin >> strEndX >> strEndY;

			key1 = Convert::ToUlonglong(strEndX, _endX) && _endX < _size;
			key2 = Convert::ToUlonglong(strEndY, _endY) && _endY < _size;

			if (!(key1 && key2)) std::cout << "Ошибка ввода данных!!!" << std::endl;

		} while (!(key1 && key2));

		Burst();
		exit = Print();

	} while (!exit);		
}

void Task7::Init()
{
	_pupyrka.resize(_size);

	for (size_t i = 0; i < _size; i++)
	{
		_pupyrka[i].resize(_size);

		for (size_t j = 0; j < _size; j++)
		{
			_pupyrka[i][j] = true;
		}
	}	
}

void Task7::Burst()
{
	size_t minColumn = std::min(_beginningX, _endX);
	size_t maxColumn = std::max(_beginningX, _endX);
	size_t minRow = std::min(_beginningY, _endY);
	size_t maxRow = std::max(_beginningY, _endY);

	for (size_t i = minRow; i <= maxRow; i++)
	{
		for (size_t j = minColumn; j <= maxColumn; j++)
		{
			if (_pupyrka[i][j])
			{
				_pupyrka[i][j] = !_pupyrka[i][j];
				std::cout << "POP!!!" << std::endl;
			}
		}
	}

	std::cout << "----------------------------------" << std::endl;
}

bool Task7::Print()
{
	system("cls");

	bool key = true;

	for (size_t i = 0; i < _size; i++)
	{
		std::cout << "|";

		for (size_t j = 0; j < _size; j++)
		{
			if (_pupyrka[i][j])
			{
				std::cout << "O";
			}
			else
			{
				std::cout << "X";
			}

			key = key && !(_pupyrka[i][j]);
		}

		std::cout << "|" << std::endl;
	}

	return key;
}
