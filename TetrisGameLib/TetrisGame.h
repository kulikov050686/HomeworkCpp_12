#pragma once
#include <locale.h>
#include <memory>
#include "../InfrastructureLib/IGame.h"

namespace TetrisGameLib
{
	/// <summary>
	/// Игра тетрис
	/// </summary>
	class TetrisGame
	{
	public:

		/// <summary>
		/// Конструктор
		/// </summary>
		TetrisGame(std::shared_ptr<IGame> game);

		/// <summary>
		/// Запуск игры
		/// </summary>
		void Run();

		/// <summary>
		/// Деструктор
		/// </summary>
		virtual ~TetrisGame() = default;

	private:

		static std::shared_ptr<IGame> _game;
	};
}
