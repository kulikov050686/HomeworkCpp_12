#pragma once
#include "IFruit.h"
#include "TypeOfFruit.h"

namespace SnakeGameLib
{
	/// <summary>
	/// ������ �����
	/// </summary>
	class Fruit : public IFruit
	{
	public:

		/// <summary>
		/// �����������
		/// </summary>
		/// <param name="coordinates"> ���������� ������ </param>
		/// <param name="typeOfFruit"> ��� ������ </param>
		Fruit(Point2D<size_t> coordinates, TypeOfFruit typeOfFruit);

		/// <summary>
		/// �������� ���������� ������
		/// </summary>		
		Point2D<size_t> GetCoordinates() override;

		/// <summary>
		/// �������� ��� ������
		/// </summary>		
		TypeOfFruit GetTypeOfFruit() override;

		/// <summary>
		/// ����������
		/// </summary>
		virtual ~Fruit() = default;

	private:

		/// <summary>
		/// ����������
		/// </summary>
		Point2D<size_t> _coordinates{ 0,0 };

		/// <summary>
		/// ��� ������
		/// </summary>
		TypeOfFruit _typeOfFruit = TypeOfFruit::APPLE;
	};
}
