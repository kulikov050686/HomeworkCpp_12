#pragma once
#include <memory>
#include "GameFieldController.h"
#include "EntityCreator.h"
#include "../InfrastructureLib/Templates.h"

namespace SnakeGameLib
{
	/// <summary>
	/// ������� ������������
	/// </summary>
	class ControllerLocator
	{
	public:

		/// <summary>
		/// �����������
		/// </summary>
		ControllerLocator() = default;

		/// <summary>
		/// �������� ���������� �������� ����
		/// </summary>		
		std::shared_ptr<GameFieldController> GetGameFieldController() { return std::make_shared<GameFieldController>(std::make_shared<GameField<uint16_t>>(40)); }
		
		/// <summary>
		/// ��������� ���������
		/// </summary>		
		std::shared_ptr<EntityCreator> GetEntityCreator() { return std::make_shared<EntityCreator>(); }

		/// <summary>
		/// ����������
		/// </summary>
		virtual ~ControllerLocator() = default;
	};
}
