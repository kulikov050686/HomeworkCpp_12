#pragma once
#include <memory>
#include "../InfrastructureLib/Templates.h"
#include "../InfrastructureLib/GameMap.h"
#include "GameMapController.h"
#include "EntityCreator.h"

namespace TetrisGameLib
{
	/// <summary>
	/// Локатор контроллеров
	/// </summary>
	class ControllerLocator
	{
	public:

		/// <summary>
		/// Конструктор
		/// </summary>
		ControllerLocator() = default;

		/// <summary>
		/// Получить контроллер игровой карты
		/// </summary>		
		std::shared_ptr<GameMapController> GetGameMapController() { return std::make_shared<GameMapController>(std::make_shared<GameMap<uint16_t>>(30, 30)); }

		/// <summary>
		/// Получить создать сущностей
		/// </summary>		
		std::shared_ptr<EntityCreator> GetEntityCreator() { return std::make_shared<EntityCreator>(); }

		/// <summary>
		/// Деструктор
		/// </summary>
		virtual ~ControllerLocator() = default;
	};
}