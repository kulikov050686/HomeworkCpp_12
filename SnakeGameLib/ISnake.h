#pragma once
#include "../InfrastructureLib/Point.h"
#include "SnakeElement.h"
#include <cstdint>

namespace SnakeGameLib
{
	/// <summary>
	/// Интерфейс модели змейка
	/// </summary>
	/// <typeparam name="T"> Тип данных элемента </typeparam>
	template <typename T>
	class ISnake
	{
	public:

		/// <summary>
		/// Конструктор
		/// </summary>
		ISnake() = default;

		/// <summary>
		/// Задать элемент
		/// </summary>
		/// <param name="element"> Элемент </param>
		virtual void SetElement(SnakeElement<T> element) = 0;

		/// <summary>
		/// Получить элемент
		/// </summary>
		/// <param name="itemNumber"> Номер элемента </param>		
		virtual SnakeElement<T> GetElement(size_t itemNumber) = 0;

		/// <summary>
		/// Обновить элемент
		/// </summary>
		/// <param name="newElement"> Элемент </param>
		virtual void UpdateElement(SnakeElement<T> newElement) = 0;
		
		/// <summary>
		/// Получить количество элементов
		/// </summary>
		virtual size_t GetNumberOfElements() = 0;

		/// <summary>
		/// Деструктор
		/// </summary>
		virtual ~ISnake() = default;
	};
}
