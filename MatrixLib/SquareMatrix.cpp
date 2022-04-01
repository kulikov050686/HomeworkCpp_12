#include "SquareMatrix.h"
#include "pch.h"

SquareMatrix::SquareMatrix(size_t size) : Matrix(size, size)
{
	this->_size = size;
}

size_t SquareMatrix::Triangulation()
{
	_numberOfPermutations = 0;
	bool key = (SizeMatrix() >= 4);
	
	for (size_t i = 0; (i < _size - 1) && key; i++)
	{
		bool key_1 = false;

		for (size_t q = i; (q < _size) && !key_1; q++)
		{
			key_1 = key_1 || (_matrix[q][i] != 0);
		}

		if (!key_1)
		{
			double max = std::abs(_matrix[i][i]);
			size_t maxPos = i;

			for (size_t k = i; k < _size; k++)
			{
				double element = std::abs(_matrix[i][k]);

				if (element > max)
				{
					max = element;
					maxPos = k;
				}
			}

			if (RearrangementOfColumns(maxPos, i))
			{
				_numberOfPermutations++;
			}
		}

		for (size_t j = i + 1; j < _size; j++)
		{
			if (_matrix[i][i] == 0.0)
			{
				double max = std::abs(_matrix[i][i]);
				size_t maxPos = i;

				for (int p = j; p < _size; p++)
				{
					double element = std::abs(_matrix[p][i]);

					if (element > max)
					{
						max = element;
						maxPos = p;
					}
				}

				if (RearrangementOfRows(maxPos, i))
				{
					_numberOfPermutations++;
				}						
			}

			if (_matrix[j, i] != 0)
			{
				double koef = _matrix[j][i] / _matrix[i][i];

				for (size_t k = i; k < _size; k++)
				{
					_matrix[j][k] -= _matrix[i][k] * koef;

					if (std::abs(_matrix[j][k]) < 0.000000001)
					{
						_matrix[j][k] = 0;
					}
				}
			}					
		}		
	}
	
	return _numberOfPermutations;
}

bool SquareMatrix::IsDiagonal()
{
	bool key = true;

	for (size_t i = 0; (i < _rows) && key; i++)
	{
		for (size_t j = 0; (j < _columns) && key; j++)
		{
			if (i == j)
			{
				key = key && (_matrix[i][j] != 0);
			}
			else
			{
				key = key && (_matrix[i][j] == 0);
			}
		}
	}

	return key;
}

bool SquareMatrix::IsTriangle()
{
	bool key_1 = !IsDiagonal();
	bool key_2 = false;

	for (size_t i = 0; i < _size; i++)
	{
		key_1 = key_1 && (_matrix[i][i] != 0);
	}

	if (key_1)
	{
		for (size_t i = 0; (i < _size) && key_1; i++)
		{
			for (size_t j = i + 1; (j < _size) && key_1; j++)
			{
				key_1 = key_1 && (_matrix[i][j] == 0);
			}
		}

		key_2 = !key_1;

		for (size_t i = _size - 1; (i >= 0) && key_2; i--)
		{
			for (size_t j = i - 1; (j >= 0) && key_2; j--)
			{
				key_2 = key_2 && (_matrix[i][j] == 0);
			}
		}
	}	

	return key_1 || key_2;
}

double SquareMatrix::Determinant()
{
	double determinant = 1;

	if (RowEquality() || ColumnEquality())
	{
		return 0;
	}

	if (IsDiagonal() || IsTriangle())
	{
		for (size_t i = 0; i < _size; i++)
		{
			determinant *= _matrix[i][i];
		}

		return determinant;
	}
	
	SquareMatrix temp(_size);

	for (size_t i = 0; i < _size; i++)
	{
		for (size_t j = 0; j < _size; j++)
		{
			temp.SetElement(i, j, _matrix[i][j]);
		}
	}

	size_t k = temp.Triangulation();

	for (size_t i = 0; i < _size; i++)
	{
		if (temp.GetElement(i, i) == 0)
		{
			return 0;
		}

		determinant *= temp.GetElement(i, i);
	}

	determinant *= std::pow(-1, k);

	return determinant;
}

void SquareMatrix::Transpose()
{
	for (size_t i = 0; i < _size - 1; i++)
	{
		for (size_t j = i + 1; j < _size; j++)
		{
			double temp = _matrix[i][j];
			_matrix[i][j] = _matrix[j][i];
			_matrix[j][i] = temp;
		}
	}
}
