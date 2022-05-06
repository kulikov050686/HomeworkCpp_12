#pragma once
#include <memory>
#include "../InfrastructureLib/IGameMap.h"
#include "../InfrastructureLib/Point.h"

namespace TetrisGameLib
{
	/// <summary>
	/// ���������� �������� ����
	/// </summary>
	class GameMapController
	{
	public:

		/// <summary>
		/// �����������
		/// </summary>
		/// <param name="map"> ������� ����� </param>
		GameMapController(std::shared_ptr<IGameMap<uint16_t>> map);

		/// <summary>
		/// �������� ������� ����
		/// </summary>
		void ClearField();

	private:

		/// <summary>
		/// �����
		/// </summary>
		std::shared_ptr<IGameMap<uint16_t>> _map;

		/// <summary>
		/// ���������� ����� �� �����
		/// </summary>
		size_t _mapRows = 0;

		/// <summary>
		/// ���������� ������� �� �����
		/// </summary>
		size_t _mapColumns = 0;

		/// <summary>
		/// ������������� �����
		/// </summary>
		void InitMap();
	};
}