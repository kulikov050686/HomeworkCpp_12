#pragma once
#include <GL/GL.h>
#include <memory>
#include "../InfrastructureLib/IGame.h"
#include "ControllerLocator.h"
#include "ColorRGB.h"

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
		Game(std::shared_ptr<ControllerLocator> controllerLocator);

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

		/// <summary>
		/// Контроллер игровой карты
		/// </summary>
		std::shared_ptr<GameMapController> _gameMapController;

		/// <summary>
		/// Создатель сущностей
		/// </summary>
		std::shared_ptr<EntityCreator> _entityCreator;

		/// <summary>
		/// Ширина окна
		/// </summary>
		int _widthWindow = 0;

		/// <summary>
		/// Высота окна
		/// </summary>
		int _heightWindow = 0;

		/// <summary>
		/// Смещение
		/// </summary>
		GLint _shift = 0;

		/// <summary>
		/// Количество очков
		/// </summary>
		size_t _numberOfPoints = 0;

		/// <summary>
		/// Завершение игры
		/// </summary>
		bool _gameOver = false;

		/// <summary>
		/// Прямоугольник
		/// </summary>		
		/// <param name="rectangleCoordinates"> Координаы прямоугольника </param>
		/// <param name="color"> Цвет </param>
		/// <param name="size"> Размер </param>
		void Rectangle(Point2D<GLint> rectangleCoordinates, ColorRGB<GLfloat> color, GLint size);
	};
}
