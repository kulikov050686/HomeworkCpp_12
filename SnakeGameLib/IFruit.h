#pragma once
#include "../InfrastructureLib/Point.h"
#include "TypeOfFruit.h"

namespace SnakeGameLib
{
	/// <summary>
	/// ��������� ������ �����
	/// </summary>
	class IFruit
	{
	public:

		/// <summary>
		/// �����������
		/// </summary>
		IFruit() = default;

		/// <summary>
		/// �������� ���������� ������
		/// </summary>		
		virtual Point2D<size_t> GetCoordinates() = 0;

		/// <summary>
		/// �������� ��� ������
		/// </summary>		
		virtual TypeOfFruit GetTypeOfFruit() = 0;

		/// <summary>
		/// ����������
		/// </summary>
		virtual ~IFruit() = default;

		/// <summary>
		/// ������ ������������
		/// </summary>		
		IFruit& operator = (const IFruit&) = delete;

		/// <summary>
		/// ������ ����������
		/// </summary>		
		IFruit(const IFruit&) = delete;
	};
}
