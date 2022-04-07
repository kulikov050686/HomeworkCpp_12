#pragma once
#include <iterator>
#include <vector>
#include "SnakeElement.h"
#include "ISnake.h"
#include "../InfrastructureLib/Point.h"

namespace SnakeGameLib
{
	/// <summary>
	/// ������ ������
	/// </summary>
	class Snake : public ISnake<uint16_t>
	{
	public:

		/// <summary>
		/// �����������
		/// </summary>
		/// <param name="initialCoordinates"> ��������� ���������� </param>
		/// <param name="elementData"> ������ ��������� </param>
		/// <param name="numberOfElements"> ��������� ���������� ��������� </param>		
		Snake(Point2D<size_t> initialCoordinates, uint16_t elementData, size_t numberOfElements = 1);

		/// <summary>
		/// �������� �������
		/// </summary>
		/// <param name="itemNumber"> ����� �������� </param>		
		SnakeElement<uint16_t> GetElement(size_t itemNumber) override;

		/// <summary>
		/// ������ �������
		/// </summary>
		/// <param name="element"> ������� </param>
		void SetElement(SnakeElement<uint16_t> element) override;

		/// <summary>
		/// ���������� ���������
		/// </summary>
		size_t GetNumberOfElements() override;

		/// <summary>
		/// ����������
		/// </summary>
		virtual ~Snake() = default;

	private:

		/// <summary>
		/// ���������� ��������� ������
		/// </summary>
		size_t _numberOfElements = 1;

		/// <summary>
		/// ������ ��������������
		/// </summary>
		size_t _lastId = 0;

		/// <summary>
		/// ������
		/// </summary>
		std::vector<SnakeElement<uint16_t>> _snake{ _numberOfElements };

		/// <summary>
		/// ������ ��������
		/// </summary>
		uint16_t _elementData = 0;

		/// <summary>
		/// �������������
		/// </summary>
		void Init();
	};
}
