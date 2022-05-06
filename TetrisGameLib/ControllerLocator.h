#pragma once
#include <memory>
#include "../InfrastructureLib/Templates.h"
#include "GameMapController.h"
#include "../InfrastructureLib/GameMap.h"

namespace TetrisGameLib
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
		/// �������� ���������� ������� �����
		/// </summary>		
		std::shared_ptr<GameMapController> GetGameMapController() { return std::make_shared<GameMapController>(std::make_shared<GameMap<uint16_t>>(30, 30)); }

		/// <summary>
		/// ����������
		/// </summary>
		virtual ~ControllerLocator() = default;
	};
}