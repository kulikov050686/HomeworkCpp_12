#pragma once
#include <iostream>
#include <memory>
#include "GameFieldController.h"
#include "../InfrastructureLib/Point.h"

namespace SnakeGameLib
{
	/// <summary>
	/// ����� ����
	/// </summary>
	class Game
	{
	public:

		/// <summary>
		/// �����������
		/// </summary>
		/// <param name="gameFieldController"> ����������� �������� ���� </param>
		Game(std::shared_ptr<GameFieldController> gameFieldController);

		/// <summary>
		/// ����� ����
		/// </summary>
		void Start();

		/// <summary>
		/// ���������
		/// </summary>
		virtual ~Game() = default;

	private:

		/// <summary>
		/// ���������� �������� ����
		/// </summary>
		std::shared_ptr<GameFieldController> _gameFieldController;
	};
}
