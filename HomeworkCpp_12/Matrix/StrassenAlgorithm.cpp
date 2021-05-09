#include "StrassenAlgorithm.h"

Matrix StrassenAlgorithm::Multiplication(Matrix& A, Matrix& B)
{
    bool EndOfCheck = false;

    if (A.GetNumberOfColumns() == B.GetNumberOfRows())
    {
        rowsMatrixOut = A.GetNumberOfRows();
        columnsMatrixOut = B.GetNumberOfColumns();

        do
        {
            if (SquareAndMultiplicityOfTwo(A) && SquareAndMultiplicityOfTwo(B))
            {
                if (MatrixComparison(A, B))
                {
                    vector_1 = Linalization(A);                    
                    vector_2 = Linalization(B);                   

                    size = A.GetNumberOfColumns();

                    EndOfCheck = true;
                }
                else
                {
                    int columnsA = A.GetNumberOfColumns();
                    int rowsA = A.GetNumberOfRows();
                    int columnsB = B.GetNumberOfColumns();
                    int rowsB = B.GetNumberOfRows();

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

bool StrassenAlgorithm::DegreeOfTwo(int number)
{
    if (number > 0)
    {
        if ((number & (number - 1)) == 0)
        {
            return true;
        }
    }

    return false;
}

bool StrassenAlgorithm::MatrixComparison(Matrix& matrix_1, Matrix& matrix_2)
{
    if (matrix_1.GetNumberOfColumns() == matrix_2.GetNumberOfColumns() && 
        matrix_1.GetNumberOfRows() == matrix_2.GetNumberOfRows())
    {
        return true;
    }

    return false;
}

bool StrassenAlgorithm::SquareAndMultiplicityOfTwo(Matrix& matrix)
{
    if (matrix.IsSquare() && DegreeOfTwo(matrix.SizeMatrix()))
    {
        return true;
    }

    return false;
}

Matrix StrassenAlgorithm::MatrixToSquare(Matrix& matrix)
{
    int rows = matrix.GetNumberOfRows();
    int columns = matrix.GetNumberOfColumns();

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
    int rows = matrix.GetNumberOfRows();
    int columns = matrix.GetNumberOfColumns();

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            vector[i * columns + j] = matrix.GetElement(i, j);
        }
    }

    return vector;
}

Matrix StrassenAlgorithm::Strassen()
{
    double* arrayOut = new double[size * size];
    Matrix matrix(size, size);
    
    mult(arrayOut, vector_1, vector_2, size);   

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            matrix.SetElement(i, j, arrayOut[i * size + j]);
        }
    }

    delete[] arrayOut;

    if (matrix.GetNumberOfColumns() == columnsMatrixOut && matrix.GetNumberOfRows() == rowsMatrixOut)
    {
        return matrix;
    }

    bool EndColumn = false;
    bool EndRow = false;

    while (!(EndColumn && EndRow))
    {
        int N = matrix.GetNumberOfColumns();
        int M = matrix.GetNumberOfRows();

        if (N == columnsMatrixOut)
        {
            EndColumn = true;
        }
        else
        {
            matrix.DeleteColumn(N - 1);
        }

        if (M == rowsMatrixOut)
        {
            EndRow = true;
        }
        else
        {
            matrix.DeleteRow(M - 1);
        }
    }

    delete[] vector_1;
    delete[] vector_2;

    return matrix;
}
