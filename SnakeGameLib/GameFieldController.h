#pragma once
#include <memory>
#include "../InfrastructureLib/Templates.h"
#include "../InfrastructureLib/Point.h"

namespace SnakeGameLib
{
	/// <summary>
	/// ���������� �������� ����
	/// </summary>
	class GameFieldController
	{
	public:

		/// <summary>
		/// �����������
		/// </summary>
		/// <param name="field"> ������� ���� </param>
		GameFieldController(std::shared_ptr<IGameField<uint16_t>> field);

		/// <summary>
		/// �������� ������ �������� ����
		/// </summary>
		uint16_t GetSizeField();

		/// <summary>
		/// �������� ������� ����
		/// </summary>
		void ClearField();

		/// <summary>
		/// ������ ������� �������� ����
		/// </summary>
		/// <param name="point"> ����� �������� ���� </param>
		/// <param name="data"> ������ </param>
		void SetFieldElement(Point2D<uint16_t> point, uint16_t data);

		/// <summary>
		/// �������� ������� �������� ����
		/// </summary>
		/// <param name="point"> ����� �������� ���� </param>
		uint16_t GetFieldElement(Point2D<uint16_t> point);

	private:

		/// <summary>
		/// ������� ����
		/// </summary>
		std::shared_ptr<IGameField<uint16_t>> _field;

		/// <summary>
		/// ������ �������� ����
		/// </summary>
		size_t _sizeField;
	};
}
