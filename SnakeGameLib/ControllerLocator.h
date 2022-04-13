#pragma once
#include <memory>
#include "GameFieldController.h"
#include "EntityCreator.h"
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
		std::shared_ptr<GameFieldController> GetGameFieldController() { return std::make_shared<GameFieldController>(std::make_shared<GameField<uint16_t>>(40)); }
		
		/// <summary>
		/// Создатель сущностей
		/// </summary>		
		std::shared_ptr<EntityCreator> GetEntityCreator() { return std::make_shared<EntityCreator>(); }

		/// <summary>
		/// Деструктор
		/// </summary>
		virtual ~ControllerLocator() = default;
	};
}
