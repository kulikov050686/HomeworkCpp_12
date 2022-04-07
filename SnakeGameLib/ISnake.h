#pragma once
#include "../InfrastructureLib/Point.h"
#include "SnakeElement.h"
#include <cstdint>

namespace SnakeGameLib
{
	/// <summary>
	/// ��������� ������ ������
	/// </summary>
	/// <typeparam name="T"> ��� ������ �������� </typeparam>
	template <typename T>
	class ISnake
	{
	public:

		/// <summary>
		/// �����������
		/// </summary>
		ISnake() = default;

		/// <summary>
		/// �������� ������� ������
		/// </summary>
		/// <param name="itemNumber"> ����� �������� </param>		
		virtual SnakeElement<T> GetElement(size_t itemNumber) = 0;

		/// <summary>
		/// ������ �������
		/// </summary>
		/// <param name="element"> ������� </param>
		virtual void SetElement(SnakeElement<T> element) = 0;

		/// <summary>
		/// �������� ���������� ���������
		/// </summary>		
		virtual size_t GetNumberOfElements() = 0;

		/// <summary>
		/// ����������
		/// </summary>
		virtual ~ISnake() = default;
	};
}
