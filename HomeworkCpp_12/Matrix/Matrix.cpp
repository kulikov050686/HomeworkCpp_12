#include "Matrix.h"

void Matrix::CreateMatrix()
{
	matrix = new double* [rows];

	for (int i = 0; i < rows; i++)
	{
		matrix[i] = new double[columns];
	}
}

void Matrix::DeleteMatrix()
{
	for (int i = 0; i < rows; i++)
	{
		delete[] matrix[i];
	}

	delete[] matrix;
	rows = 0;
	columns = 0;
}

void Matrix::CreateTempMatrix()
{
	tempMatrix = new double* [tempRows];

	for (int i = 0; i < tempRows; i++)
	{
		tempMatrix[i] = new double[tempColumns];
	}
}

void Matrix::DeleteTempMatrix()
{
	for (int i = 0; i < tempRows; i++)
	{
		delete[] tempMatrix[i];
	}

	delete[] tempMatrix;
	tempRows = 0;
	tempColumns = 0;
}

void Matrix::CopyMatrixToTempMatrix()
{
	for (int i = 0; i < tempRows; i++)
	{
		for (int j = 0; j < tempColumns; j++)
		{
			tempMatrix[i][j] = matrix[i][j];
		}
	}
}

Matrix::Matrix(int numberOfRow, int numberOfColumns)
{
	if (numberOfRow > 0 && numberOfColumns > 0)
	{
		rows = numberOfRow;
		columns = numberOfColumns;
		CreateMatrix();
	}
	else
	{
		throw;
	}	
}

Matrix::Matrix(const Matrix& other)
{
	rows = other.rows;
	columns = other.columns;

	CreateMatrix();

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			matrix[i][j] = other.matrix[i][j];
		}
	}
}

int Matrix::GetNumberOfRows()
{
	return rows;
}

int Matrix::GetNumberOfColumns()
{
	return columns;
}

bool Matrix::IsSquare()
{
	return rows == columns;
}

int Matrix::SizeMatrix()
{
	return rows * columns;
}

double Matrix::GetElement(int row, int column)
{
	return matrix[row][column];
}

void Matrix::SetElement(int row, int column, double data)
{
	matrix[row][column] = data;
}

bool Matrix::AddColumnsAtBack(int numberOfColumns)
{
	if (numberOfColumns > 0)
	{
		tempRows = rows;
		tempColumns = columns;

		CreateTempMatrix();
		CopyMatrixToTempMatrix();
		DeleteMatrix();

		int tempColumn = tempColumns;
		columns = tempColumns + numberOfColumns;
		rows = tempRows;
		
		CreateMatrix();

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				if (j < tempColumn)
				{
					matrix[i][j] = tempMatrix[i][j];
				}
				else
				{
					matrix[i][j] = 0;
				}
			}
		}

		DeleteTempMatrix();
		return true;
	}

	return false;
}

bool Matrix::DeleteColumn(int columnNumber)
{
	if (columns > 1)
	{
		if (0 <= columnNumber && columnNumber < columns)
		{
			tempRows = rows;
			tempColumns = columns - 1;
			CreateTempMatrix();

			for (int i = 0; i < rows; i++)
			{
				for (int j = 0, p = 0; j < columns - 1; j++, p++)
				{
					if (p == columnNumber)
					{
						p++;
					}

					tempMatrix[i][j] = matrix[i][p];
				}
			}

			DeleteMatrix();

			rows = tempRows;
			columns = tempColumns;
			
			CreateMatrix();

			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < columns; j++)
				{
					matrix[i][j] = tempMatrix[i][j];
				}
			}

			DeleteTempMatrix();
			return true;
		}
	}

	return false;
}

bool Matrix::AddRowsAtBottom(int numberOfRows)
{
	if (numberOfRows > 0)
	{
		tempRows = rows;
		tempColumns = columns;

		CreateTempMatrix();
		CopyMatrixToTempMatrix();
		DeleteMatrix();
		
		int tempRow = tempRows;
		rows = tempRows + numberOfRows;
		columns = tempColumns;

		CreateMatrix();

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				if (i < tempRow)
				{
					matrix[i][j] = tempMatrix[i][j];
				}
				else
				{
					matrix[i][j] = 0;
				}
			}
		}

		DeleteTempMatrix();
		return true;
	}

	return false;
}

bool Matrix::DeleteRow(int rowNumber)
{
	if (rows > 1)
	{
		if (0 <= rowNumber && rowNumber < rows)
		{
			tempRows = rows - 1;
			tempColumns = columns;
			CreateTempMatrix();
			
			for (int i = 0, p = 0; i < rows - 1; i++, p++)
			{
				for (int j = 0; j < columns; j++)
				{
					if (p == rowNumber)
					{
						p++;
					}

					tempMatrix[i][j] = matrix[p][j];
				}
			}

			DeleteMatrix();

			rows = tempRows;
			columns = tempColumns;

			CreateMatrix();

			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < columns; j++)
				{
					matrix[i][j] = tempMatrix[i][j];
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
	tempRows = rows;
	tempColumns = columns;

	CreateTempMatrix();
	CopyMatrixToTempMatrix();
	DeleteMatrix();

	rows = tempColumns;
	columns = tempRows;

	CreateMatrix();

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			matrix[i][j] = tempMatrix[j][i];
		}
	}

	DeleteTempMatrix();	
}

bool Matrix::RearrangementOfRows(int n, int k)
{
	if ((0 <= n && n < rows) && (0 <= k && k < rows) && (n != k))
	{
		double temp = 0;

		for (int i = 0; i < columns; i++)
		{
			temp = matrix[n][i];
			matrix[n][i] = matrix[k][i];
			matrix[k][i] = temp;
		}

		return true;
	}

	return false;
}

bool Matrix::RearrangementOfColumns(int n, int k)
{
	if ((0 <= n && n < columns) && (0 <= k && k < columns) && (n != k))
	{
		double temp = 0;

		for (int i = 0; i < rows; i++)
		{
			temp = matrix[i][n];
			matrix[i][n] = matrix[i][k];
			matrix[i][k] = temp;
		}

		return true;
	}

	return false;
}

double Matrix::MaximumElementInColumn(int column)
{
	double max = matrix[0][0];

	for (int i = 0; i < rows; i++)
	{
		if (matrix[i][column] > max)
		{
			max = matrix[i][column];
		}
	}

	return max;
}

double Matrix::MaximumElementInRow(int row)
{
	double max = matrix[0][0];

	for (int i = 0; i < columns; i++)
	{
		if (matrix[row][i] > max)
		{
			max = matrix[row][i];
		}
	}

	return max;
}

double Matrix::MinimumElementInColumn(int column)
{
	double min = matrix[0][0];

	for (int i = 0; i < rows; i++)
	{
		if (matrix[i][column] < min)
		{
			min = matrix[i][column];
		}
	}

	return min;
}

double Matrix::MinimumElementInRow(int row)
{
	double min = matrix[0][0];

	for (int i = 0; i < columns; i++)
	{
		if (matrix[row][i] < min)
		{
			min = matrix[row][i];
		}
	}

	return min;
}

double Matrix::MatrixMaximumElement()
{
	double maxElement = matrix[0][0];
	
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (matrix[i][j] > maxElement)
			{
				maxElement = matrix[i][j];
			}
		}
	}

	return maxElement;
}

double Matrix::MatrixMinimumElement()
{
	double minElement = matrix[0][0];

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (matrix[i][j] < minElement)
			{
				minElement = matrix[i][j];
			}
		}
	}

	return minElement;
}

void Matrix::MultiplyMatrixByNumber(double number)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			matrix[i][j] = number * matrix[i][j];
		}
	}
}

void Matrix::MultiplyColumnByNumber(double number, int column)
{
	for  (int i = 0; i < rows; i++)
	{
		matrix[i][column] = number * matrix[i][column];
	}
}

void Matrix::MultiplyRowByNumber(double number, int row)
{
	for (int i = 0; i < columns; i++)
	{
		matrix[row][i] = number * matrix[row][i];
	}
}

bool Matrix::ColumnEquality()
{
	bool key_1 = true;

	for (int i = 0; (i < columns) && key_1; i++)
	{
		for (int j = columns - 1; (j > i) && key_1; j--)
		{
			bool key_2 = true;

			for (int r = 0; (r < rows) && key_2; r++)
			{
				key_2 = key_2 && (matrix[r][i] == matrix[r][j]);
			}

			key_1 = key_1 && !key_2;
		}
	}

	return !key_1;
}

bool Matrix::RowEquality()
{
	bool key_1 = true;

	for (int i = 0; (i < rows) && key_1; i++)
	{
		for (int j = rows - 1; (j > i) && key_1; j--)
		{
			bool key_2 = true;

			for (int r = 0; (r < columns) && key_2; r++)
			{
				key_2 = key_2 && (matrix[i][r] == matrix[j][r]);
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

	if ((rows == other.rows) && (columns == other.columns))
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				matrix[i][j] = other.matrix[i][j];
			}
		}
	}
	else
	{
		DeleteMatrix();

		rows = other.rows;
		columns = other.columns;

		CreateMatrix();

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				matrix[i][j] = other.matrix[i][j];
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

	if ((rows == other.rows) && (columns == other.columns))
	{
		bool key = true;

		for (int i = 0; (i < rows) && key; i++)
		{
			for (int j = 0; j < columns && key; j++)
			{
				key = key && (matrix[i][j] == other.matrix[i][j]);
			}
		}

		return key;
	}

	return false;
}
