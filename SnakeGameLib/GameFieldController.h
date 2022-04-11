#pragma once
#include <memory>
#include "../InfrastructureLib/Templates.h"
#include "../InfrastructureLib/Point.h"
#include "../RandomLib/Random.h"
#include "IFruit.h"
#include "ISnake.h"
#include "TypeOfFruit.h"

namespace SnakeGameLib
{
	/// <summary>
	/// Контроллер игрового поля
	/// </summary>
	class GameFieldController
	{
	public:

		/// <summary>
		/// Конструктор
		/// </summary>
		/// <param name="field"> Игровое поле </param>
		GameFieldController(std::shared_ptr<IGameField<uint16_t>> field);

		/// <summary>
		/// Получить размер игрового поля
		/// </summary>
		uint16_t GetSizeField();

		/// <summary>
		/// Очистить игровое поле
		/// </summary>
		void ClearField();

		/// <summary>
		/// Задать элемент игрового поля
		/// </summary>
		/// <param name="point"> Точка игрового поля </param>
		/// <param name="data"> Данные </param>
		void SetFieldElement(Point2D<uint16_t> point, uint16_t data);

		/// <summary>
		/// Получить элемент игрового поля
		/// </summary>
		/// <param name="point"> Точка игрового поля </param>
		uint16_t GetFieldElement(Point2D<uint16_t> point);

		/// <summary>
		/// Добавить змейку на игровое поле
		/// </summary>
		/// <param name="snake"> Змейка </param>		
		bool AddSnakeOnField(std::shared_ptr<ISnake<uint16_t>> snake);

		/// <summary>
		/// Добавить фрукт на поле
		/// </summary>
		/// <param name="fruit"> Фрукт </param>		
		bool AddFruitOnField(std::shared_ptr<IFruit> fruit);

		/// <summary>
		/// Принадлежность точки игровой области
		/// </summary>
		/// <param name="point"> Точка </param>		
		bool BelongingToPointOfGameArea(Point2D<size_t> point);

		/// <summary>
		/// Создать случайную точку принадлежащую игровой области
		/// </summary>		
		Point2D<size_t> CreateRandomPoint();

	private:

		/// <summary>
		/// Игровое поле
		/// </summary>
		std::shared_ptr<IGameField<uint16_t>> _field;
		
		/// <summary>
		/// Размер игрового поля
		/// </summary>
		size_t _sizeField = 0;

		/// <summary>
		/// Инициализация поля
		/// </summary>
		void InitField();
	};
}
