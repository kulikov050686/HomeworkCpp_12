#pragma once
#include <memory>
#include "Fruit.h"
#include "../InfrastructureLib/Point.h"
#include "TypeOfFruit.h"

namespace SnakeGameLib
{
	/// <summary>
	/// ���������� ������
	/// </summary>
	class FruitController
	{
	public:
		
		/// <summary>
		/// �����������
		/// </summary>
		FruitController() = default;

		/// <summary>
		/// ������� �����
		/// </summary>
		/// <param name="coordinates"> ���������� ������ </param>
		/// <param name="typeOfFruit"> ��� ������ </param>		
		std::shared_ptr<IFruit> CreateFruit(Point2D<size_t> coordinates, TypeOfFruit typeOfFruit);

		/// <summary>
		/// ����������
		/// </summary>
		virtual ~FruitController() = default;

	private:

		/// <summary>
		/// ������ �����������
		/// </summary>		
		FruitController(const FruitController&) = delete;

		/// <summary>
		/// ������ ������������
		/// </summary>		
		FruitController& operator = (const FruitController&) = delete;
	};
}
