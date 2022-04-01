#pragma once
#include <locale.h>
#include <memory>
#include "../InfrastructureLib/Templates.h"

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
