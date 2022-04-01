#include "Matrix.h"
#include "pch.h"

void Matrix::CreateMatrix()
{
	_matrix = new double* [_rows];

	for (size_t i = 0; i < _rows; i++)
	{
		_matrix[i] = new double[_columns];
	}
}

void Matrix::DeleteMatrix()
{
	for (size_t i = 0; i < _rows; i++)
	{
		delete[] _matrix[i];
	}

	delete[] _matrix;
	_rows = 0;
	_columns = 0;
}

void Matrix::CreateTempMatrix()
{
	_tempMatrix = new double* [_tempRows];

	for (size_t i = 0; i < _tempRows; i++)
	{
		_tempMatrix[i] = new double[_tempColumns];
	}
}

void Matrix::DeleteTempMatrix()
{
	for (size_t i = 0; i < _tempRows; i++)
	{
		delete[] _tempMatrix[i];
	}

	delete[] _tempMatrix;
	_tempRows = 0;
	_tempColumns = 0;
}

void Matrix::CopyMatrixToTempMatrix()
{
	for (size_t i = 0; i < _tempRows; i++)
	{
		for (size_t j = 0; j < _tempColumns; j++)
		{
			_tempMatrix[i][j] = _matrix[i][j];
		}
	}
}

Matrix::Matrix(size_t numberOfRow, size_t numberOfColumns)
{
	if (numberOfRow > 0 && numberOfColumns > 0)
	{
		_rows = numberOfRow;
		_columns = numberOfColumns;
		CreateMatrix();
	}
	else
	{
		throw "Error!!!";
	}	
}

Matrix::Matrix(const Matrix& other)
{
	_rows = other._rows;
	_columns = other._columns;

	CreateMatrix();

	for (size_t i = 0; i < _rows; i++)
	{
		for (size_t j = 0; j < _columns; j++)
		{
			_matrix[i][j] = other._matrix[i][j];
		}
	}
}

size_t Matrix::GetNumberOfRows()
{
	return _rows;
}

size_t Matrix::GetNumberOfColumns()
{
	return _columns;
}

bool Matrix::IsSquare()
{
	return _rows == _columns;
}

size_t Matrix::SizeMatrix()
{
	return _rows * _columns;
}

double Matrix::GetElement(size_t row, size_t column)
{
	return _matrix[row][column];
}

void Matrix::SetElement(size_t row, size_t column, double data)
{
	_matrix[row][column] = data;
}

bool Matrix::AddColumnsAtBack(size_t numberOfColumns)
{
	if (numberOfColumns > 0)
	{
		_tempRows = _rows;
		_tempColumns = _columns;

		CreateTempMatrix();
		CopyMatrixToTempMatrix();
		DeleteMatrix();

		size_t tempColumn = _tempColumns;
		_columns = _tempColumns + numberOfColumns;
		_rows = _tempRows;
		
		CreateMatrix();

		for (size_t i = 0; i < _rows; i++)
		{
			for (size_t j = 0; j < _columns; j++)
			{
				if (j < tempColumn)
				{
					_matrix[i][j] = _tempMatrix[i][j];
				}
				else
				{
					_matrix[i][j] = 0;
				}
			}
		}

		DeleteTempMatrix();
		return true;
	}

	return false;
}

bool Matrix::DeleteColumn(size_t columnNumber)
{
	if (_columns > 1)
	{
		if (0 <= columnNumber && columnNumber < _columns)
		{
			_tempRows = _rows;
			_tempColumns = _columns - 1;
			CreateTempMatrix();

			for (size_t i = 0; i < _rows; i++)
			{
				for (size_t j = 0, p = 0; j < _columns - 1; j++, p++)
				{
					if (p == columnNumber)
					{
						p++;
					}

					_tempMatrix[i][j] = _matrix[i][p];
				}
			}

			DeleteMatrix();

			_rows = _tempRows;
			_columns = _tempColumns;
			
			CreateMatrix();

			for (size_t i = 0; i < _rows; i++)
			{
				for (size_t j = 0; j < _columns; j++)
				{
					_matrix[i][j] = _tempMatrix[i][j];
				}
			}

			DeleteTempMatrix();
			return true;
		}
	}

	return false;
}

bool Matrix::AddRowsAtBottom(size_t numberOfRows)
{
	if (numberOfRows > 0)
	{
		_tempRows = _rows;
		_tempColumns = _columns;

		CreateTempMatrix();
		CopyMatrixToTempMatrix();
		DeleteMatrix();
		
		size_t tempRow = _tempRows;
		_rows = _tempRows + numberOfRows;
		_columns = _tempColumns;

		CreateMatrix();

		for (size_t i = 0; i < _rows; i++)
		{
			for (size_t j = 0; j < _columns; j++)
			{
				if (i < tempRow)
				{
					_matrix[i][j] = _tempMatrix[i][j];
				}
				else
				{
					_matrix[i][j] = 0;
				}
			}
		}

		DeleteTempMatrix();
		return true;
	}

	return false;
}

bool Matrix::DeleteRow(size_t rowNumber)
{
	if (_rows > 1)
	{
		if (0 <= rowNumber && rowNumber < _rows)
		{
			_tempRows = _rows - 1;
			_tempColumns = _columns;
			CreateTempMatrix();
			
			for (size_t i = 0, p = 0; i < _rows - 1; i++, p++)
			{
				for (size_t j = 0; j < _columns; j++)
				{
					if (p == rowNumber)
					{
						p++;
					}

					_tempMatrix[i][j] = _matrix[p][j];
				}
			}

			DeleteMatrix();

			_rows = _tempRows;
			_columns = _tempColumns;

			CreateMatrix();

			for (size_t i = 0; i < _rows; i++)
			{
				for (size_t j = 0; j < _columns; j++)
				{
					_matrix[i][j] = _tempMatrix[i][j];
				}
			}

			DeleteTempMatrix();
			return true;
		}
	}

	return false;
}

void Matrix::Transpose()
{
	_tempRows = _rows;
	_tempColumns = _columns;

	CreateTempMatrix();
	CopyMatrixToTempMatrix();
	DeleteMatrix();

	_rows = _tempColumns;
	_columns = _tempRows;

	CreateMatrix();

	for (size_t i = 0; i < _rows; i++)
	{
		for (size_t j = 0; j < _columns; j++)
		{
			_matrix[i][j] = _tempMatrix[j][i];
		}
	}

	DeleteTempMatrix();	
}

bool Matrix::RearrangementOfRows(size_t n, size_t k)
{
	if ((0 <= n && n < _rows) && (0 <= k && k < _rows) && (n != k))
	{
		double temp = 0;

		for (size_t i = 0; i < _columns; i++)
		{
			temp = _matrix[n][i];
			_matrix[n][i] = _matrix[k][i];
			_matrix[k][i] = temp;
		}

		return true;
	}

	return false;
}

bool Matrix::RearrangementOfColumns(size_t n, size_t k)
{
	if ((0 <= n && n < _columns) && (0 <= k && k < _columns) && (n != k))
	{
		double temp = 0;

		for (size_t i = 0; i < _rows; i++)
		{
			temp = _matrix[i][n];
			_matrix[i][n] = _matrix[i][k];
			_matrix[i][k] = temp;
		}

		return true;
	}

	return false;
}

double Matrix::MaximumElementInColumn(size_t column)
{
	double max = _matrix[0][0];

	for (size_t i = 0; i < _rows; i++)
	{
		if (_matrix[i][column] > max)
		{
			max = _matrix[i][column];
		}
	}

	return max;
}

double Matrix::MaximumElementInRow(size_t row)
{
	double max = _matrix[0][0];

	for (size_t i = 0; i < _columns; i++)
	{
		if (_matrix[row][i] > max)
		{
			max = _matrix[row][i];
		}
	}

	return max;
}

double Matrix::MinimumElementInColumn(size_t column)
{
	double min = _matrix[0][0];

	for (size_t i = 0; i < _rows; i++)
	{
		if (_matrix[i][column] < min)
		{
			min = _matrix[i][column];
		}
	}

	return min;
}

double Matrix::MinimumElementInRow(size_t row)
{
	double min = _matrix[0][0];

	for (size_t i = 0; i < _columns; i++)
	{
		if (_matrix[row][i] < min)
		{
			min = _matrix[row][i];
		}
	}

	return min;
}

double Matrix::MatrixMaximumElement()
{
	double maxElement = _matrix[0][0];
	
	for (size_t i = 0; i < _rows; i++)
	{
		for (size_t j = 0; j < _columns; j++)
		{
			if (_matrix[i][j] > maxElement)
			{
				maxElement = _matrix[i][j];
			}
		}
	}

	return maxElement;
}

double Matrix::MatrixMinimumElement()
{
	double minElement = _matrix[0][0];

	for (size_t i = 0; i < _rows; i++)
	{
		for (size_t j = 0; j < _columns; j++)
		{
			if (_matrix[i][j] < minElement)
			{
				minElement = _matrix[i][j];
			}
		}
	}

	return minElement;
}

void Matrix::MultiplyMatrixByNumber(double number)
{
	for (size_t i = 0; i < _rows; i++)
	{
		for (size_t j = 0; j < _columns; j++)
		{
			_matrix[i][j] = number * _matrix[i][j];
		}
	}
}

void Matrix::MultiplyColumnByNumber(double number, size_t column)
{
	for  (size_t i = 0; i < _rows; i++)
	{
		_matrix[i][column] = number * _matrix[i][column];
	}
}

void Matrix::MultiplyRowByNumber(double number, size_t row)
{
	for (size_t i = 0; i < _columns; i++)
	{
		_matrix[row][i] = number * _matrix[row][i];
	}
}

bool Matrix::ColumnEquality()
{
	bool key_1 = true;

	for (size_t i = 0; (i < _columns) && key_1; i++)
	{
		for (size_t j = _columns - 1; (j > i) && key_1; j--)
		{
			bool key_2 = true;

			for (size_t r = 0; (r < _rows) && key_2; r++)
			{
				key_2 = key_2 && (_matrix[r][i] == _matrix[r][j]);
			}

			key_1 = key_1 && !key_2;
		}
	}

	return !key_1;
}

bool Matrix::RowEquality()
{
	bool key_1 = true;

	for (size_t i = 0; (i < _rows) && key_1; i++)
	{
		for (size_t j = _rows - 1; (j > i) && key_1; j--)
		{
			bool key_2 = true;

			for (size_t r = 0; (r < _columns) && key_2; r++)
			{
				key_2 = key_2 && (_matrix[i][r] == _matrix[j][r]);
			}

			key_1 = key_1 && !key_2;
		}
	}

	return !key_1;
}

Matrix::~Matrix()
{
	DeleteMatrix();
}

Matrix& Matrix::operator = (const Matrix& other)
{
	if (this == &other)
	{
		return *this;
	}

	if ((_rows == other._rows) && (_columns == other._columns))
	{
		for (size_t i = 0; i < _rows; i++)
		{
			for (size_t j = 0; j < _columns; j++)
			{
				_matrix[i][j] = other._matrix[i][j];
			}
		}
	}
	else
	{
		DeleteMatrix();

		_rows = other._rows;
		_columns = other._columns;

		CreateMatrix();

		for (size_t i = 0; i < _rows; i++)
		{
			for (size_t j = 0; j < _columns; j++)
			{
				_matrix[i][j] = other._matrix[i][j];
			}
		}
	}	

	return *this;
}

bool Matrix::operator == (const Matrix& other)
{
	if (this == &other)
	{
		return true;
	}

	if ((_rows == other._rows) && (_columns == other._columns))
	{
		bool key = true;

		for (size_t i = 0; (i < _rows) && key; i++)
		{
			for (size_t j = 0; j < _columns && key; j++)
			{
				key = key && (_matrix[i][j] == other._matrix[i][j]);
			}
		}

		return key;
	}

	return false;
}
