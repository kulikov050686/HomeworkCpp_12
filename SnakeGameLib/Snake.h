#pragma once
#include <iterator>
#include <vector>
#include "SnakeElement.h"
#include "ISnake.h"
#include "../InfrastructureLib/Point.h"

namespace SnakeGameLib
{
	/// <summary>
	/// Модель змейка
	/// </summary>
	class Snake : public ISnake<uint16_t>
	{
	public:

		/// <summary>
		/// Конструктор
		/// </summary>
		/// <param name="initialCoordinates"> Начальные координаты </param>
		/// <param name="elementData"> Данные элементов </param>
		/// <param name="numberOfElements"> Начальное количество элементов </param>		
		Snake(Point2D<size_t> initialCoordinates, uint16_t elementData, size_t numberOfElements = 1);

		/// <summary>
		/// Получить элемент
		/// </summary>
		/// <param name="itemNumber"> Номер элемента </param>		
		SnakeElement<uint16_t> GetElement(size_t itemNumber) override;

		/// <summary>
		/// Задать элемент
		/// </summary>
		/// <param name="element"> Элемент </param>
		void SetElement(SnakeElement<uint16_t> element) override;

		/// <summary>
		/// Количество элементов
		/// </summary>
		size_t GetNumberOfElements() override;

		/// <summary>
		/// Деструктор
		/// </summary>
		virtual ~Snake() = default;

	private:

		/// <summary>
		/// Количество элементов змейки
		/// </summary>
		size_t _numberOfElements = 1;

		/// <summary>
		/// Номера идентификатора
		/// </summary>
		size_t _lastId = 0;

		/// <summary>
		/// Змейка
		/// </summary>
		std::vector<SnakeElement<uint16_t>> _snake{ _numberOfElements };

		/// <summary>
		/// Данные элемента
		/// </summary>
		uint16_t _elementData = 0;

		/// <summary>
		/// Инициализация
		/// </summary>
		void Init();
	};
}
