#pragma once
#include "../InfrastructureLib/Point.h"

namespace SnakeGameLib
{
	/// <summary>
	/// ������� ������
	/// </summary>
	/// <typeparam name="T"> ��� �������� </typeparam>
	template <typename T>
	struct SnakeElement
	{
		/// <summary>
		/// �������������
		/// </summary>
		size_t id;

		/// <summary>
		/// ����������
		/// </summary>
		Point2D<size_t> coordinates;

		/// <summary>
		/// �������
		/// </summary>
		T element;
	};
}
