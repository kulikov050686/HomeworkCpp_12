#pragma once
#include <memory>
#include "../InfrastructureLib/IGameMap.h"
#include "../InfrastructureLib/Point.h"

namespace TetrisGameLib
{
	/// <summary>
	/// Контроллер игрового поля
	/// </summary>
	class GameMapController
	{
	public:

		/// <summary>
		/// Конструктор
		/// </summary>
		/// <param name="map"> Игровая карта </param>
		GameMapController(std::shared_ptr<IGameMap<uint16_t>> map);

		/// <summary>
		/// Получить количество рядов карты
		/// </summary>		
		size_t GetNumberOfRows();

		/// <summary>
		/// Получить количество колонок карты
		/// </summary>		
		size_t GetNumberOfColumns();

		/// <summary>
		/// Очистить игровое поле
		/// </summary>
		void ClearField();

		/// <summary>
		/// Получить элемент игровой карты
		/// </summary>
		/// <param name="point"> Точка игровой карты </param>		
		uint16_t GetFieldElement(Point2D<uint16_t> point);

	private:

		/// <summary>
		/// Карта
		/// </summary>
		std::shared_ptr<IGameMap<uint16_t>> _map;

		/// <summary>
		/// Количество рядов на карте
		/// </summary>
		size_t _mapRows = 0;

		/// <summary>
		/// Количество колонок на карте
		/// </summary>
		size_t _mapColumns = 0;

		/// <summary>
		/// Инициализация карты
		/// </summary>
		void InitMap();
	};
}