#include "pch.h"
#include "Task2.h"

void Task2::Run()
{
	system("cls");
	setlocale(LC_ALL, "Russian.utf8");

	bool exit = false;
	
	while (!exit)
	{
		Screensaver();
		Init();
		Print();
		GameLogic();

		try
		{
			exit = MenuGameOver();
		}
		catch (const std::exception& ex)
		{
			exit = true;
		}		
	}	
}

void Task2::SetMenuGameOver(std::shared_ptr<IMenuController> menuController)
{
	_menuGameOver = menuController;
}

void Task2::Init()
{
	_field = { {'*','*','*'},
			   {'*','*','*'},
			   {'*','*','*'} };

	_quantityX = 0;
	_quantityO = 0;
	_numberOfMoves = 0;
	_gameOver = false;
}

bool Task2::CorrectInput(const char symbol)
{
	return symbol == 'X' ||
		   symbol == 'O';
}

bool Task2::FreeCell(size_t x, size_t y)
{
	return _field[x][y] == '*';
}

bool Task2::Victory(const char symbol)
{
	bool key0 = true;
	bool key1 = true;
	bool key2 = false;
	bool key3 = false;

	for(size_t i = 0; i < _size && !key2 && !key3; i++)
	{
		key0 = key0 && (_field[i][_size - 1 - i] == symbol);
		key1 = key1 && (_field[i][i] == symbol);

		key2 = true;
		key3 = true;

		for (size_t j = 0; j < _size; j++)
		{
			key2 = key2 && (_field[i][j] == symbol);
			key3 = key3 && (_field[j][i] == symbol);
		}
	}

	return key0 || key1 || key2 || key3;
}

bool Task2::EnterCharacter(const char chr, const size_t x, const size_t y)
{
	std::string symbol = "";

	std::cout << "Введите " << chr << ":";
	std::cin >> symbol;

	if (symbol.length() == 1 && CorrectInput(symbol[0]) && symbol[0] == chr)
	{
		_field[x][y] = symbol[0];
		_numberOfMoves++;
		
		if (symbol[0] == 'O') _quantityO++;
		if (symbol[0] == 'X') _quantityX++;

		Print();

		if (_numberOfMoves >= 5)
		{
			_gameOver = Victory(symbol[0]);
		}

		if (_gameOver)
		{
			std::cout << "Выигрыш " << symbol[0] << "!" << std::endl;
			std::cin;
		}

		return true;
	}

	return false;
}

void Task2::Print()
{
	std::cout << "--------------------------------" << std::endl;

	for (size_t i = 0; i < _size; i++)
	{
		std::cout << "|";

		for (size_t j = 0; j < _size; j++)
		{
			std::cout << _field[i][j];
		}

		std::cout << "|" << std::endl;
	}

	std::cout << "--------------------------------" << std::endl;
}

bool Task2::MenuGameOver()
{
	if (_menuGameOver != nullptr)
	{
		std::string text = "Завершить игру?";

		switch (_menuGameOver->SelectedMenuItem(text))
		{
			case 0: return true;
			case 1: return false;
		}
	}

	throw "Menu Controller cannot be null!!!";
}

void Task2::Screensaver()
{
	system("cls");
	setlocale(LC_ALL, "Russian.utf8");	

	std::vector<std::string> text = { {"/////////////////////"},
									  {"// Крестики нолики //"},
									  {"/////////////////////"} };
	
	std::cout << text[2] << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(1));
	system("cls");

	std::cout << text[1] << std::endl;
	std::cout << text[2] << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(1));
	system("cls");

	std::cout << text[0] << std::endl;
	std::cout << text[1] << std::endl;
	std::cout << text[2] << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(1));
	system("cls");
}

void Task2::GameLogic()
{
	size_t x = 0;
	size_t y = 0;	
	std::string strX = "";
	std::string strY = "";

	while (!_gameOver)
	{
		std::cout << "Введите координату (через пробел): ";
		std::cin >> strX >> strY;

		if (Convert::ToUlonglong(strX, x) && Convert::ToUlonglong(strY, y))
		{
			if (x < _size && y < _size)
			{
				if (FreeCell(x, y))
				{
					bool key = true;

					if (_quantityX > _quantityO)
					{
						while (key)
						{
							if (EnterCharacter('O', x, y))
							{
								key = false;
							}
							else
							{
								std::cout << "Ошибка ввода данных!" << std::endl;
							}
						}
					}
					else
					{
						while (key)
						{
							if (EnterCharacter('X', x, y))
							{
								key = false;
							}
							else
							{
								std::cout << "Ошибка ввода данных!" << std::endl;
							}
						}
					}

					if (!_gameOver && _numberOfMoves == 9)
					{
						_gameOver = true;
						std::cout << "Ничья!!!" << std::endl;
						std::cin;
					}
				}
				else
				{
					std::cout << "Ячейка занята!" << std::endl;
				}
			}
			else
			{
				std::cout << "Ошибка ввода данных!" << std::endl;
			}
		}
		else
		{
			std::cout << "Ошибка ввода данных!" << std::endl;
		}
	}
}
