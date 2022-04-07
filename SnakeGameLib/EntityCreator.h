#pragma once
#include <memory>
#include "../InfrastructureLib/Point.h"
#include "IFruit.h"
#include "ISnake.h"
#include "TypeOfFruit.h"
#include "Fruit.h"
#include "Snake.h"

namespace SnakeGameLib
{
	/// <summary>
	/// ��������� ���������
	/// </summary>
	class EntityCreator
	{
	public:

		/// <summary>
		/// �����������
		/// </summary>
		EntityCreator() = default;
		
		/// <summary>
		/// ������� �����
		/// </summary>
		/// <param name="coordinates"> ���������� ������ </param>
		/// <param name="typeOfFruit"> ��� ������ </param>		
		std::shared_ptr<IFruit> CreateFruit(Point2D<size_t> coordinates, TypeOfFruit typeOfFruit);

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
		virtual ~EntityCreator() = default;
	};
}
