#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <chrono>
#include <thread>
#include "ITask.h"
#include "../ConvertLib/Convert.h"
#include "../MenuLib/MenuController.h"

/// <summary>
/// Задача 2
/// </summary>
class Task2 : public ITask
{
public:

	/// <summary>
	/// Конструктор
	/// </summary>
	Task2() = default;

	/// <summary>
	/// Запуск
	/// </summary>
	void Run() override;

	/// <summary>
	/// Задать меню завершения игры
	/// </summary>
	/// <param name="menuController"> Контроллер меню </param>
	void SetMenuGameOver(std::shared_ptr<IMenuController> menuController);

	/// <summary>
	/// Деструктор
	/// </summary>
	virtual ~Task2() = default;

private:

	/// <summary>
	/// Размер игрового поля
	/// </summary>
	size_t _size = 3;

	/// <summary>
	/// Количество X
	/// </summary>
	size_t _quantityX = 0;

	/// <summary>
	/// Количество O
	/// </summary>
	size_t _quantityO = 0;

	/// <summary>
	/// Количество ходов
	/// </summary>
	size_t _numberOfMoves = 0;
	
	/// <summary>
	/// Игровое поле
	/// </summary>
	std::vector<std::vector<char>> _field;

	/// <summary>
	/// Меню завершения игры 
	/// </summary>
	std::shared_ptr<IMenuController> _menuGameOver;

	/// <summary>
	/// Завершение игры
	/// </summary>
	bool _gameOver = false;

	/// <summary>
	/// Инициализация
	/// </summary>
	void Init();

	/// <summary>
	/// Корректность ввода символа
	/// </summary>
	/// <param name="symbol"> Символ </param>	
	bool CorrectInput(const char symbol);

	/// <summary>
	/// Свободная ячейка
	/// </summary>
	/// <param name="x"> Координата x </param>
	/// <param name="y"> Координата y </param>	
	bool FreeCell(size_t x, size_t y);

	/// <summary>
	/// Победа
	/// </summary>
	/// <param name="symbol"> Символ </param>	
	bool Victory(const char symbol);

	/// <summary>
	/// Ввести символ
	/// </summary>
	/// <param name="symbol"> Символ </param>
	/// <param name="x"> Координата x символа </param>
	/// <param name="y"> Координата y символа </param>	
	bool EnterCharacter(const char chr, const size_t x, const size_t y);

	/// <summary>
	/// Печать игрового поля
	/// </summary>
	void Print();

	/// <summary>
	/// Меню выхода
	/// </summary>		
	bool MenuGameOver();

	/// <summary>
	/// Начальная заставка
	/// </summary>
	void Screensaver();

	/// <summary>
	/// Игровая логика
	/// </summary>
	void GameLogic();
};
