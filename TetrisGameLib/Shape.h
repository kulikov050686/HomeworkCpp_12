#pragma once
#include <vector>
#include "IShape.h"
#include "ShapeEnum.h"

namespace TetrisGameLib
{
	/// <summary>
	/// Фигура
	/// </summary>
	class Shape : public IShape 
	{
	public:

		/// <summary>
		/// Конструктор
		/// </summary>
		/// <param name="x"> Координата x </param>
		/// <param name="y"> Координата y </param>
		/// <param name="shapeEnum"> Форма фигуры </param>
		Shape(size_t x, size_t y, ShapeEnum shapeEnum);

		/// <summary>
		/// Передвинуть вниз
		/// </summary>
		void MoveDown() override;

		/// <summary>
		/// Передвинуть вправо
		/// </summary>
		void MoveRight() override;

		/// <summary>
		/// Передвинуть влево
		/// </summary>
		void MoveLeft() override;

		/// <summary>
		/// Вращение фигуры
		/// </summary>
		void RotateShape() override;

		/// <summary>
		/// Получить фигуру
		/// </summary>		
		std::vector<std::vector<uint16_t>> GetShape() const override;

		/// <summary>
		///  Деструктор
		/// </summary>
		virtual ~Shape() = default;
		
	private:

		/// <summary>
		/// Координата x
		/// </summary>
		size_t _x = 0;

		/// <summary>
		/// Координата y
		/// </summary>
		size_t _y = 0;

		/// <summary>
		/// Форма фигуры
		/// </summary>
		ShapeEnum _shapeEnum = ShapeEnum::FIGURE_1;

		/// <summary>
		/// Размер матрицы фигуры
		/// </summary>
		size_t _sizeMatrix = 0;

		/// <summary>
		/// Матрица фигуры
		/// </summary>
		std::vector<std::vector<uint16_t>> _matrix;

		/// <summary>
		/// Инициализация
		/// </summary>
		void Init();
	};
}
