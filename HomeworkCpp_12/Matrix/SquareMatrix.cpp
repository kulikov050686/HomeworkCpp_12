#include "SquareMatrix.h"

SquareMatrix::SquareMatrix(int size) : Matrix(size, size)
{
	this->size = size;
}

int SquareMatrix::Triangulation()
{
	numberOfPermutations = 0;
	bool key = (SizeMatrix() >= 4);
	
	for (int i = 0; (i < size - 1) && key; i++)
	{
		bool key_1 = false;

		for (int q = i; (q < size) && !key_1; q++)
		{
			key_1 = key_1 || (matrix[q][i] != 0);
		}

		if (!key_1)
		{
			double max = std::abs(matrix[i][i]);
			int maxPos = i;

			for (int k = i; k < size; k++)
			{
				double element = std::abs(matrix[i][k]);

				if (element > max)
				{
					max = element;
					maxPos = k;
				}
			}

			if (RearrangementOfColumns(maxPos, i))
			{
				numberOfPermutations++;
			}
		}

		for (int j = i + 1; j < size; j++)
		{
			if (matrix[i][i] == 0)
			{
				double max = std::abs(matrix[i][i]);
				int maxPos = i;

				for (int p = j; p < size; p++)
				{
					double element = std::abs(matrix[p][i]);

					if (element > max)
					{
						max = element;
						maxPos = p;
					}
				}

				if (RearrangementOfRows(maxPos, i))
				{
					numberOfPermutations++;
				}						
			}

			if (matrix[j, i] != 0)
			{
				double koef = matrix[j][i] / matrix[i][i];

				for (int k = i; k < size; k++)
				{
					matrix[j][k] -= matrix[i][k] * koef;

					if (std::abs(matrix[j][k]) < 0.000000001)
					{
						matrix[j][k] = 0;
					}
				}
			}					
		}		
	}
	
	return numberOfPermutations;
}

bool SquareMatrix::IsDiagonal()
{
	bool key = true;

	for (int i = 0; (i < rows) && key; i++)
	{
		for (int j = 0; (j < columns) && key; j++)
		{
			if (i == j)
			{
				key = key && (matrix[i][j] != 0);
			}
			else
			{
				key = key && (matrix[i][j] == 0);
			}
		}
	}

	return key;
}

bool SquareMatrix::IsTriangle()
{
	bool key_1 = !IsDiagonal();
	bool key_2 = false;

	for (int i = 0; i < size; i++)
	{
		key_1 = key_1 && (matrix[i][i] != 0);
	}

	if (key_1)
	{
		for (int i = 0; (i < size) && key_1; i++)
		{
			for (int j = i + 1; (j < size) && key_1; j++)
			{
				key_1 = key_1 && (matrix[i][j] == 0);
			}
		}

		key_2 = !key_1;

		for (int i = size - 1; (i >= 0) && key_2; i--)
		{
			for (int j = i - 1; (j >= 0) && key_2; j--)
			{
				key_2 = key_2 && (matrix[i][j] == 0);
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
		for (int i = 0; i < size; i++)
		{
			determinant *= matrix[i][i];
		}

		return determinant;
	}
	
	SquareMatrix temp(size);

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			temp.SetElement(i, j, matrix[i][j]);
		}
	}

	int k = temp.Triangulation();

	for (int i = 0; i < size; i++)
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
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			double temp = matrix[i][j];
			matrix[i][j] = matrix[j][i];
			matrix[j][i] = temp;
		}
	}
}
