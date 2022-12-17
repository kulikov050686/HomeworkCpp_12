#pragma once
#include <vector>

namespace TetrisGameLib
{
	/// <summary>
	/// Интерфейс фигура
	/// </summary>
	class IShape
	{
	public:

		/// <summary>
		/// Конструктор
		/// </summary>
		IShape() = default;
		
		/// <summary>
		/// Передвинуть вниз
		/// </summary>
		virtual void MoveDown() = 0;

		/// <summary>
		/// Передвинуть вправо
		/// </summary>
		virtual void MoveRight() = 0;

		/// <summary>
		/// Передвинуть влево
		/// </summary>
		virtual void MoveLeft() = 0;

		/// <summary>
		/// Вращение фигуры
		/// </summary>
		virtual void RotateShape() = 0;

		/// <summary>
		/// Получить фигуру
		/// </summary>		
		virtual std::vector<std::vector<uint16_t>> GetShape() const = 0;

		/// <summary>
		/// Деструктор
		/// </summary>
		virtual ~IShape() = default;
	};
}
