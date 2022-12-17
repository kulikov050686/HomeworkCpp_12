#pragma once
#include <vector>
#include "IShape.h"
#include "ShapeEnum.h"

namespace TetrisGameLib
{
	/// <summary>
	/// ������
	/// </summary>
	class Shape : public IShape 
	{
	public:

		/// <summary>
		/// �����������
		/// </summary>
		/// <param name="x"> ���������� x </param>
		/// <param name="y"> ���������� y </param>
		/// <param name="shapeEnum"> ����� ������ </param>
		Shape(size_t x, size_t y, ShapeEnum shapeEnum);

		/// <summary>
		/// ����������� ����
		/// </summary>
		void MoveDown() override;

		/// <summary>
		/// ����������� ������
		/// </summary>
		void MoveRight() override;

		/// <summary>
		/// ����������� �����
		/// </summary>
		void MoveLeft() override;

		/// <summary>
		/// �������� ������
		/// </summary>
		void RotateShape() override;

		/// <summary>
		/// �������� ������
		/// </summary>		
		std::vector<std::vector<uint16_t>> GetShape() const override;

		/// <summary>
		///  ����������
		/// </summary>
		virtual ~Shape() = default;
		
	private:

		/// <summary>
		/// ���������� x
		/// </summary>
		size_t _x = 0;

		/// <summary>
		/// ���������� y
		/// </summary>
		size_t _y = 0;

		/// <summary>
		/// ����� ������
		/// </summary>
		ShapeEnum _shapeEnum = ShapeEnum::FIGURE_1;

		/// <summary>
		/// ������ ������� ������
		/// </summary>
		size_t _sizeMatrix = 0;

		/// <summary>
		/// ������� ������
		/// </summary>
		std::vector<std::vector<uint16_t>> _matrix;

		/// <summary>
		/// �������������
		/// </summary>
		void Init();
	};
}
