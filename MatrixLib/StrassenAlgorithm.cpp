#include "StrassenAlgorithm.h"
#include "pch.h"

Matrix StrassenAlgorithm::Multiplication(Matrix& A, Matrix& B)
{
    bool EndOfCheck = false;

    if (A.GetNumberOfColumns() == B.GetNumberOfRows())
    {
        _rowsMatrixOut = A.GetNumberOfRows();
        _columnsMatrixOut = B.GetNumberOfColumns();

        do
        {
            if (SquareAndMultiplicityOfTwo(A) && SquareAndMultiplicityOfTwo(B))
            {
                if (MatrixComparison(A, B))
                {
                    _vector_1 = Linalization(A);                    
                    _vector_2 = Linalization(B);                   

                    _size = A.GetNumberOfColumns();

                    EndOfCheck = true;
                }
                else
                {
                    size_t columnsA = A.GetNumberOfColumns();
                    size_t rowsA = A.GetNumberOfRows();
                    size_t columnsB = B.GetNumberOfColumns();
                    size_t rowsB = B.GetNumberOfRows();

                    if (A.SizeMatrix() > B.SizeMatrix())
                    {
                        B.AddColumnsAtBack(columnsA - columnsB);
                        B.AddRowsAtBottom(rowsA - rowsB);
                    }

                    if (B.SizeMatrix() > A.SizeMatrix())
                    {
                        A.AddColumnsAtBack(columnsB - columnsA);
                        A.AddRowsAtBottom(rowsB - rowsA);
                    }
                }
            }
            else
            {
                if (!SquareAndMultiplicityOfTwo(A))
                {
                    A = MatrixSquareMultipleOfTwo(A);
                }

                if (!SquareAndMultiplicityOfTwo(B))
                {
                    B = MatrixSquareMultipleOfTwo(B);
                }
            }
        } while (!EndOfCheck);

        return Strassen();
    }

    throw;
}

bool StrassenAlgorithm::DegreeOfTwo(size_t number)
{
    return (number > 0) && ((number & (number - 1)) == 0);
}

bool StrassenAlgorithm::MatrixComparison(Matrix& matrix_1, Matrix& matrix_2)
{
    return (matrix_1.GetNumberOfColumns() == matrix_2.GetNumberOfColumns()) &&
           (matrix_1.GetNumberOfRows() == matrix_2.GetNumberOfRows());
}

bool StrassenAlgorithm::SquareAndMultiplicityOfTwo(Matrix& matrix)
{
    return matrix.IsSquare() && DegreeOfTwo(matrix.SizeMatrix());
}

Matrix StrassenAlgorithm::MatrixToSquare(Matrix& matrix)
{
    size_t rows = matrix.GetNumberOfRows();
    size_t columns = matrix.GetNumberOfColumns();

    if (columns > rows)
    {
        matrix.AddRowsAtBottom(columns - rows);
    }

    if (columns < rows)
    {
        matrix.AddColumnsAtBack(rows - columns);
    }

    return matrix;
}

Matrix StrassenAlgorithm::MatrixSquareMultipleOfTwo(Matrix& matrix)
{
    if (matrix.IsSquare())
    {
        matrix.AddColumnsAtBack(1);
        matrix.AddRowsAtBottom(1);

        return matrix;
    }
    else
    {
        matrix = MatrixToSquare(matrix);

        if (DegreeOfTwo(matrix.SizeMatrix()))
        {
            return matrix;
        }
        else
        {
            matrix.AddColumnsAtBack(1);
            matrix.AddRowsAtBottom(1);
        }
    }

    return matrix;
}

double* StrassenAlgorithm::Linalization(Matrix& matrix)
{    
    double* vector = new double[matrix.SizeMatrix()];
    size_t rows = matrix.GetNumberOfRows();
    size_t columns = matrix.GetNumberOfColumns();

    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            vector[i * columns + j] = matrix.GetElement(i, j);
        }
    }

    return vector;
}

Matrix StrassenAlgorithm::Strassen()
{
    double* arrayOut = new double[_size * _size];
    Matrix matrix(_size, _size);
    
    Mult(arrayOut, _vector_1, _vector_2, _size);   

    for (size_t i = 0; i < _size; i++)
    {
        for (size_t j = 0; j < _size; j++)
        {
            matrix.SetElement(i, j, arrayOut[i * _size + j]);
        }
    }

    delete[] arrayOut;    

    if (matrix.GetNumberOfColumns() == _columnsMatrixOut && matrix.GetNumberOfRows() == _rowsMatrixOut)
    {
        return matrix;
    }

    bool EndColumn = false;
    bool EndRow = false;

    while (!(EndColumn && EndRow))
    {
        size_t N = matrix.GetNumberOfColumns();
        size_t M = matrix.GetNumberOfRows();

        if (N == _columnsMatrixOut)
        {
            EndColumn = true;
        }
        else
        {
            matrix.DeleteColumn(N - 1);
        }

        if (M == _rowsMatrixOut)
        {
            EndRow = true;
        }
        else
        {
            matrix.DeleteRow(M - 1);
        }
    }

    delete[] _vector_1;
    delete[] _vector_2;

    return matrix;
}
