#pragma once
#include "freeglut/include/GL/freeglut.h"
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

		/// <summary>
		/// Игра
		/// </summary>
		static std::shared_ptr<IGame> _game;

		/// <summary>
		/// Ширина окна
		/// </summary>
		int _widthWindow = 1000;

		/// <summary>
		/// Высота окна
		/// </summary>
		int _heightWindow = 1000;

		/// <summary>
		/// Отрисовка
		/// </summary>
		static void Display();

		/// <summary>
		/// Таймер
		/// </summary>
		/// <param name="value"> Передаваемый параметр </param>
		static void Timer(int value);

		/// <summary>
		/// Изменения размеров окна
		/// </summary>
		/// <param name="width"> Высота окна </param>
		/// <param name="height"> Ширина окна </param>
		static void Reshape(int width, int height);

		/// <summary>
		/// Нажатая клавиша клавиатуры
		/// </summary>
		/// <param name="key"> Символ клавиши </param>
		/// <param name="x"> Координата x мыши </param>
		/// <param name="y"> Координата y мыши </param>
		static void Keyboard(unsigned char key, int x, int y);
	};
}
