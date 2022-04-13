#pragma once
#include "freeglut/include/GL/freeglut.h"
#include <iostream>
#include <memory>
#include "../InfrastructureLib/IGame.h"

namespace SnakeGameLib
{
	/// <summary>
	/// Игра змейка
	/// </summary>
	class SnakeGame
	{
	public:

		/// <summary>
		/// Конструктор
		/// </summary>
		SnakeGame(std::shared_ptr<IGame> game);

		/// <summary>
		/// Запуск игры
		/// </summary>
		void Run();

		/// <summary>
		/// Деструктор
		/// </summary>
		virtual ~SnakeGame() = default;		

	private:

		/// <summary>
		/// Игра
		/// </summary>
		std::shared_ptr<IGame> _game;

		/// <summary>
		/// Ширина окна
		/// </summary>
		int _widthWindow = 640;

		/// <summary>
		/// Высота окна
		/// </summary>
		int _heightWindow = 480;
		
		/// <summary>
		/// Функция отрисовки
		/// </summary>
		void static Display();		
	};	
}
