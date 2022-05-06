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
		/// Очистить игровое поле
		/// </summary>
		void ClearField();

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