#pragma once
#include <iostream>

/// <summary>
/// Класс матрица
/// </summary>
class Matrix
{
protected:
	
	/// <summary>
	/// Основная матрица
	/// </summary>
	 double** _matrix;

	/// <summary>
	/// Временная матрица
	/// </summary>
	 double** _tempMatrix;

	/// <summary>
	/// Количество колонок в основной матрице
	/// </summary>
	size_t _columns = 0;

	/// <summary>
	/// Количество рядов в основной матрице
	/// </summary>
	size_t _rows = 0;

	/// <summary>
	/// Количество рядов во временной матрице
	/// </summary>
	size_t _tempRows = 0;

	/// <summary>
	/// Количество колонок во временоой матрице
	/// </summary>
	size_t _tempColumns = 0;
	
	/// <summary>
	/// Создание основной матрицы
	/// </summary>
	void CreateMatrix();

	/// <summary>
	/// Удаление основной матрицы
	/// </summary>
	void DeleteMatrix();

	/// <summary>
	/// Создание временной матрицы
	/// </summary>
	void CreateTempMatrix();

	/// <summary>
	/// Удаление временной матрицы
	/// </summary>
	void DeleteTempMatrix();

	/// <summary>
	/// Копирование данных из основной матрицы во временную
	/// </summary>
	void CopyMatrixToTempMatrix();

public:

	/// <summary>
	/// Конструктор
	/// </summary>
	/// <param name="NumberOfRow"> Количество рядов </param>
	/// <param name="NumberOfColumns"> Количество колонок </param>
	Matrix(size_t numberOfRow, size_t numberOfColumns);

	/// <summary>
	/// Конструктор копирования
	/// </summary>
	/// <param name="other"> Копируемая матрица </param>
	Matrix(const Matrix& other);

	/// <summary>
	/// Получить количество рядов матрицы
	/// </summary>	
	size_t GetNumberOfRows();

	/// <summary>
	/// Получить количество колонок матрицы
	/// </summary>	
	size_t GetNumberOfColumns();

	/// <summary>
	/// Проверка на квадратность матрицы
	/// </summary>	
	bool IsSquare();

	/// <summary>
	/// Размер матрицы
	/// </summary>	
	size_t SizeMatrix();

	/// <summary>
	/// Получить данные элемента матрицы
	/// </summary>
	/// <param name="row"> Номер ряда </param>
	/// <param name="column"> Номер колонки </param>	
	double GetElement(size_t row, size_t column);

	/// <summary>
	/// Задать данные элемента матрицы
	/// </summary>
	/// <param name="row"> Номер ряда </param>
	/// <param name="column"> Номер столбца </param>
	/// <param name="data"> Данные </param>	
	void SetElement(size_t row, size_t column, double data);

	/// <summary>
	/// Добавить колонки в конец
	/// </summary>
	/// <param name="numberOfColumns"> Количество добавляемых колонок </param>	
	bool AddColumnsAtBack(size_t numberOfColumns);

	/// <summary>
	/// Удаление колонку по номеру
	/// </summary>
	/// <param name="columnNumber"> Номер колонки </param>	
	bool DeleteColumn(size_t columnNumber);

	/// <summary>
	/// Добавить ряд снизу
	/// </summary>
	/// <param name="numberOfRows"> Количество добавляемых рядов </param>	
	bool AddRowsAtBottom(size_t numberOfRows);

	/// <summary>
	/// Удалить ряд по номеру
	/// </summary>
	/// <param name="rowNumber"> Номер ряда </param>	
	bool DeleteRow(size_t rowNumber);

	/// <summary>
	/// Транспонирование
	/// </summary>
	void Transpose();

	/// <summary>
	/// Перестановка рядов местами
	/// </summary>
	/// <param name="n"> Номер первого ряда </param>
	/// <param name="k"> Hомер второго ряда </param>
	bool RearrangementOfRows(size_t n, size_t k);

	/// <summary>
	/// Перестановка колонок местами
	/// </summary>
	/// <param name="n"> Номер первой колонки </param>
	/// <param name="k"> Номер второй колонки </param>	
	bool RearrangementOfColumns(size_t n, size_t k);
	
	/// <summary>
	/// Максимальный элемент в колонке
	/// </summary>
	/// <param name="column"> Номер колонки </param>	
	double MaximumElementInColumn(size_t column);

	/// <summary>
	/// Максимальный элемент в ряду
	/// </summary>
	/// <param name="row"> Номер ряда </param>	
	double MaximumElementInRow(size_t row);

	/// <summary>
	/// Минимальный элемент в колонке
	/// </summary>
	/// <param name="column"> Номер колонки </param>	
	double MinimumElementInColumn(size_t column);

	/// <summary>
	/// Минимальный элемент в ряду
	/// </summary>
	/// <param name="row"> Номер ряда </param>	
	double MinimumElementInRow(size_t row);

	/// <summary>
	/// Максимальный элемент матрицы
	/// </summary>	
	double MatrixMaximumElement();

	/// <summary>
	/// Минимальный элемент матрицы
	/// </summary>	
	double MatrixMinimumElement();

	/// <summary>
	/// Умножение матрицы на число
	/// </summary>
	/// <param name="number"> Число </param>
	void MultiplyMatrixByNumber(double number);

	/// <summary>
	/// Умножение колонки на число
	/// </summary>
	/// <param name="number"> Чсило </param>
	/// <param name="column"> Номер колонки </param>
	void MultiplyColumnByNumber(double number, size_t column);

	/// <summary>
	/// Умножение ряда на число
	/// </summary>
	/// <param name="number"> Число </param>
	/// <param name="row"> Номер ряда </param>
	void MultiplyRowByNumber(double number, size_t row);

	/// <summary>
	/// Равенство дух колонок
	/// </summary>
	bool ColumnEquality();

	/// <summary>
	/// Равенство двух рядов
	/// </summary>	
	bool RowEquality();

	/// <summary>
	/// Деструктор
	/// </summary>
	virtual ~Matrix();

	/// <summary>
	/// Перегрузка оператора присваивания
	/// </summary>	
	Matrix& operator = (const Matrix& other);

	/// <summary>
	/// Перегрузка оператора сравнения
	/// </summary>	
	bool operator == (const Matrix& other);
};
