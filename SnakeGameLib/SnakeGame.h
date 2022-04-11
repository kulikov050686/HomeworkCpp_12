#pragma once
#include "GLEW/include/glew.h"
#include "GL/include/glfw3.h"
#include <iostream>
#include <memory>
#include "ControllerLocator.h"
#include "Game.h"

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
		SnakeGame() = default;

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
		/// Запрет присваивания
		/// </summary>	
		SnakeGame& operator = (const SnakeGame&) = delete;

		/// <summary>
		/// Запрет копирования
		/// </summary>	
		SnakeGame(const SnakeGame&) = delete;
	};
}
