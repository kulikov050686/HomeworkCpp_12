#include "MatrixOperations.h"
#include "pch.h"

bool MatrixOperations::AddAndSubResolution(Matrix& matrix_1, Matrix& matrix_2)
{
	return (matrix_1.GetNumberOfRows() == matrix_2.GetNumberOfRows()) &&
		   (matrix_1.GetNumberOfColumns() == matrix_2.GetNumberOfColumns());
}

bool MatrixOperations::MultResolution(Matrix& matrix_1, Matrix& matrix_2)
{
	return matrix_1.GetNumberOfColumns() == matrix_2.GetNumberOfRows();
}

Matrix MatrixOperations::Addition(Matrix& matrix_1, Matrix& matrix_2)
{
	size_t rows = matrix_1.GetNumberOfRows();
	size_t columns = matrix_1.GetNumberOfColumns();

	if (rows == matrix_2.GetNumberOfRows() &&
		columns == matrix_2.GetNumberOfColumns())
	{
		Matrix temp(rows, columns);

		for (size_t i = 0; i < rows; i++)
		{
			for (size_t j = 0; j < columns; j++)
			{
				temp.SetElement(i, j, matrix_1.GetElement(i, j) + matrix_2.GetElement(i, j));
			}
		}

		return temp;
	}

	throw;
}

Matrix MatrixOperations::Subtraction(Matrix& matrix_1, Matrix& matrix_2)
{
	size_t rows = matrix_1.GetNumberOfRows();
	size_t columns = matrix_1.GetNumberOfColumns();

	if (rows == matrix_2.GetNumberOfRows() &&
		columns == matrix_2.GetNumberOfColumns())
	{
		Matrix temp(rows, columns);

		for (size_t i = 0; i < rows; i++)
		{
			for (size_t j = 0; j < columns; j++)
			{
				temp.SetElement(i, j, matrix_1.GetElement(i, j) - matrix_2.GetElement(i, j));
			}
		}

		return temp;
	}

	throw;
}

Matrix MatrixOperations::Multiplication(Matrix& matrix_1, Matrix& matrix_2)
{
	double data = 0;
	size_t columnsA = matrix_1.GetNumberOfColumns();
	size_t rowsA = matrix_1.GetNumberOfRows();
	size_t columnsB = matrix_2.GetNumberOfColumns();
	size_t rowsB = matrix_2.GetNumberOfRows();

	if (columnsA == rowsB)
	{
		Matrix matrix_3(rowsA, columnsB);
		double* vector = new double[rowsB];

		for (size_t i = 0; i < columnsB; i++)
		{
			for (size_t p = 0; p < rowsB; p++)
			{
				vector[p] = matrix_2.GetElement(p, i);
			}

			for (size_t j = 0; j < rowsA; j++)
			{
				for (size_t k = 0; k < columnsA; k++)
				{
					data += matrix_1.GetElement(j, k) * vector[k];
				}

				matrix_3.SetElement(j, i, data);
				data = 0;
			}
		}

		delete[] vector;
		return matrix_3;
	}

	throw;
}

Matrix MatrixOperations::MultiplicationVinohradStrassen(Matrix& matrix_1, Matrix& matrix_2)
{
	Matrix A = matrix_1;
	Matrix B = matrix_2;
	//StrassenAlgorithm* strassenAlgorithm = new StrassenAlgorithm();

	//return strassenAlgorithm->Multiplication(A, B);

	return matrix_1;
}
