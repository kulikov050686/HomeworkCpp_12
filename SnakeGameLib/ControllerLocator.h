#pragma once
#include <memory>
#include "GameFieldController.h"
#include "FruitController.h"
#include "SnakeController.h"
#include "../InfrastructureLib/Templates.h"

namespace SnakeGameLib
{
	/// <summary>
	/// Локатор Контроллеров
	/// </summary>
	class ControllerLocator
	{
	public:

		/// <summary>
		/// Конструктор
		/// </summary>
		ControllerLocator() = default;

		/// <summary>
		/// Получить контроллер игрового поля
		/// </summary>		
		std::shared_ptr<GameFieldController> GetGameFieldController() { return std::make_shared<GameFieldController>(std::make_shared<GameField<uint16_t>>(10)); }

		/// <summary>
		/// Получить контроллер змейки
		/// </summary>		
		std::shared_ptr<SnakeController> GetSnakeController() { return std::make_shared<SnakeController>(); }

		/// <summary>
		/// Получить контроллер фрукта
		/// </summary>		
		std::shared_ptr<FruitController> GetFruitController() { return std::make_shared<FruitController>(); }
		
		/// <summary>
		/// Деструктор
		/// </summary>
		virtual ~ControllerLocator() = default;
	};
}
