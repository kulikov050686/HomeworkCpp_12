#pragma once
#include <memory>
#include "ISnake.h"
#include "Snake.h"

namespace SnakeGameLib
{
	/// <summary>
	/// ���������� ������
	/// </summary>
	class SnakeController
	{
	public:

		/// <summary>
		/// �����������
		/// </summary>
		SnakeController() = default;
		
		/// <summary>
		/// ������� ������
		/// </summary>
		/// <param name="initialCoordinates"> ��������� ���������� </param>
		/// <param name="elementData"> ������ �������� ������ </param>
		/// <param name="numberOfElements"> ���������� ��������� ������ </param>		
		std::shared_ptr<ISnake<uint16_t>> CreateSnake(Point2D<size_t> initialCoordinates,
													  uint16_t elementData, 
										              size_t numberOfElements = 4);

		/// <summary>
		/// ����������
		/// </summary>
		virtual ~SnakeController() = default;
	};
}
