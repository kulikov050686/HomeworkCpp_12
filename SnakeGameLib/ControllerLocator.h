#pragma once
#include <memory>
#include "GameFieldController.h"
#include "FruitController.h"
#include "SnakeController.h"
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
		std::shared_ptr<GameFieldController> GetGameFieldController() { return std::make_shared<GameFieldController>(std::make_shared<GameField<uint16_t>>(10)); }

		/// <summary>
		/// �������� ���������� ������
		/// </summary>		
		std::shared_ptr<SnakeController> GetSnakeController() { return std::make_shared<SnakeController>(); }

		/// <summary>
		/// �������� ���������� ������
		/// </summary>		
		std::shared_ptr<FruitController> GetFruitController() { return std::make_shared<FruitController>(); }
		
		/// <summary>
		/// ����������
		/// </summary>
		virtual ~ControllerLocator() = default;
	};
}
