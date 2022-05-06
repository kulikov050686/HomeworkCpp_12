#pragma once
#include "../InfrastructureLib/IGame.h"

namespace TetrisGameLib
{
	/// <summary>
	/// Игра
	/// </summary>
	class Game : public IGame
	{
	public:

		/// <summary>
		/// Конструктор
		/// </summary>
		Game() = default;

		/// <summary>
		/// Отрисовка
		/// </summary>
		void Draw() override;

		/// <summary>
		/// Обработка событий таймера
		/// </summary>
		/// <param name="value"> Параметр </param>
		void Timer(int value) override;

		/// <summary>
		/// Обработка событий изменения размеров окна
		/// </summary>
		/// <param name="width"> Ширина окна </param>
		/// <param name="height"> Высота окна </param>
	    void Reshape(int width, int height) override;

		/// <summary>
		/// Обработка событий клавиатуры
		/// </summary>
		/// <param name="key"> Код клавиши </param>
		/// <param name="x"> Координата x мыши </param>
		/// <param name="y"> Координата y мыши </param>
		void Keyboard(unsigned char key, int x, int y) override;

		/// <summary>
		/// Обработка событий времени бездействия
		/// </summary>
		void Idel() override;

		/// <summary>
		/// Деструктор
		/// </summary>
		virtual ~Game() = default;

	private:
	};
}
