#pragma once
#include <memory>
#include "../InfrastructureLib/Templates.h"
#include "../InfrastructureLib/Point.h"

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

	private:

		/// <summary>
		/// Игровое поле
		/// </summary>
		std::shared_ptr<IGameField<uint16_t>> _field;

		/// <summary>
		/// Размер игрового поля
		/// </summary>
		size_t _sizeField;
	};
}
