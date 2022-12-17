#pragma once
#include <vector>

namespace TetrisGameLib
{
	/// <summary>
	/// ��������� ������
	/// </summary>
	class IShape
	{
	public:

		/// <summary>
		/// �����������
		/// </summary>
		IShape() = default;
		
		/// <summary>
		/// ����������� ����
		/// </summary>
		virtual void MoveDown() = 0;

		/// <summary>
		/// ����������� ������
		/// </summary>
		virtual void MoveRight() = 0;

		/// <summary>
		/// ����������� �����
		/// </summary>
		virtual void MoveLeft() = 0;

		/// <summary>
		/// �������� ������
		/// </summary>
		virtual void RotateShape() = 0;

		/// <summary>
		/// �������� ������
		/// </summary>		
		virtual std::vector<std::vector<uint16_t>> GetShape() const = 0;

		/// <summary>
		/// ����������
		/// </summary>
		virtual ~IShape() = default;
	};
}
