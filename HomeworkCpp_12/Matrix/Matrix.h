#pragma once
#include <iostream>

class Matrix
{
protected:
	
	/// <summary>
	/// Основная матрица
	/// </summary>
	 double** matrix;

	/// <summary>
	/// Временная матрица
	/// </summary>
	 double** tempMatrix;

	/// <summary>
	/// Количество колонок в основной матрице
	/// </summary>
	int columns = 0;

	/// <summary>
	/// Количество рядов в основной матрице
	/// </summary>
	int rows = 0;

	/// <summary>
	/// Количество рядов во временной матрице
	/// </summary>
	int tempRows = 0;

	/// <summary>
	/// Количество колонок во временоой матрице
	/// </summary>
	int tempColumns = 0;
	
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
	Matrix(int numberOfRow, int numberOfColumns);

	/// <summary>
	/// Конструктор копирования
	/// </summary>
	/// <param name="other"> Копируемая матрица </param>
	Matrix(const Matrix& other);

	/// <summary>
	/// Получить количество рядов матрицы
	/// </summary>	
	int GetNumberOfRows();

	/// <summary>
	/// Получить количество колонок матрицы
	/// </summary>	
	int GetNumberOfColumns();

	/// <summary>
	/// Проверка на квадратность матрицы
	/// </summary>	
	bool IsSquare();

	/// <summary>
	/// Размер матрицы
	/// </summary>	
	int SizeMatrix();

	/// <summary>
	/// Получить данные элемента матрицы
	/// </summary>
	/// <param name="row"> Номер ряда </param>
	/// <param name="column"> Номер колонки </param>	
	double GetElement(int row, int column);

	/// <summary>
	/// Задать данные элемента матрицы
	/// </summary>
	/// <param name="row"> Номер ряда </param>
	/// <param name="column"> Номер столбца </param>
	/// <param name="data"> Данные </param>	
	void SetElement(int row, int column, double data);

	/// <summary>
	/// Добавить колонки в конец
	/// </summary>
	/// <param name="numberOfColumns"> Количество добавляемых колонок </param>	
	bool AddColumnsAtBack(int numberOfColumns);

	/// <summary>
	/// Удаление колонку по номеру
	/// </summary>
	/// <param name="columnNumber"> Номер колонки </param>	
	bool DeleteColumn(int columnNumber);

	/// <summary>
	/// Добавить ряд снизу
	/// </summary>
	/// <param name="numberOfRows"> Количество добавляемых рядов </param>	
	bool AddRowsAtBottom(int numberOfRows);

	/// <summary>
	/// Удалить ряд по номеру
	/// </summary>
	/// <param name="rowNumber"> Номер ряда </param>	
	bool DeleteRow(int rowNumber);

	/// <summary>
	/// Транспонирование
	/// </summary>
	void Transpose();

	/// <summary>
	/// Перестановка рядов местами
	/// </summary>
	/// <param name="n"> Номер первого ряда </param>
	/// <param name="k"> Hомер второго ряда </param>
	bool RearrangementOfRows(int n, int k);

	/// <summary>
	/// Перестановка колонок местами
	/// </summary>
	/// <param name="n"> Номер первой колонки </param>
	/// <param name="k"> Номер второй колонки </param>	
	bool RearrangementOfColumns(int n, int k);
	
	/// <summary>
	/// Максимальный элемент в колонке
	/// </summary>
	/// <param name="column"> Номер колонки </param>	
	double MaximumElementInColumn(int column);

	/// <summary>
	/// Максимальный элемент в ряду
	/// </summary>
	/// <param name="row"> Номер ряда </param>	
	double MaximumElementInRow(int row);

	/// <summary>
	/// Минимальный элемент в колонке
	/// </summary>
	/// <param name="column"> Номер колонки </param>	
	double MinimumElementInColumn(int column);

	/// <summary>
	/// Минимальный элемент в ряду
	/// </summary>
	/// <param name="row"> Номер ряда </param>	
	double MinimumElementInRow(int row);

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
	void MultiplyColumnByNumber(double number, int column);

	/// <summary>
	/// Умножение ряда на число
	/// </summary>
	/// <param name="number"> Число </param>
	/// <param name="row"> Номер ряда </param>
	void MultiplyRowByNumber(double number, int row);

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
	~Matrix();

	/// <summary>
	/// Перегрузка оператора присваивания
	/// </summary>	
	Matrix& operator = (const Matrix& other);

	/// <summary>
	/// Перегрузка оператора сравнения
	/// </summary>	
	bool operator == (const Matrix& other);
};
