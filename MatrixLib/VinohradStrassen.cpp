#include "VinohradStrassen.h"
#include "pch.h"

void VinohradStrassen::MultStandart(double* c, double* a, double* b, size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            c[i * n + j] = 0;

            for (size_t k = 0; k < n; k++)
            {
                c[i * n + j] += a[i * n + k] * b[k * n + j];
            }
        }
    }
}

void VinohradStrassen::Mult(double* c, double* a, double* b, size_t n)
{
    if (n <= 2)
    {
        MultStandart(c, a, b, n);
    }
    else
    {
        size_t h = n / 2;
        double* M = new double[h * h * 29];

        //0-3: четверти матрицы A
        Copy(&M[0], a, 0, 0, n);         //M[0] = A11
        Copy(&M[h * h], a, 0, h, n);     //M[1] = A12
        Copy(&M[2 * h * h], a, h, 0, n); //M[2] = A21
        Copy(&M[3 * h * h], a, h, h, n); //M[3] = A22

        //4-7: четверти матрицы B
        Copy(&M[4 * h * h], b, 0, 0, n); //M[4] = B11
        Copy(&M[5 * h * h], b, 0, h, n); //M[5] = B12
        Copy(&M[6 * h * h], b, h, 0, n); //M[6] = B21
        Copy(&M[7 * h * h], b, h, h, n); //M[7] = B22

        //8-15: S1 - S8
        Add(&M[8 * h * h], &M[2 * h * h], &M[3 * h * h], h);   //M[8] = S1 = A21 + A22
        Sub(&M[9 * h * h], &M[8 * h * h], &M[0], h);           //M[9] = S2 = S1 - A11
        Sub(&M[10 * h * h], &M[0], &M[2 * h * h], h);          //M[10] = S3 = A11 - A21
        Sub(&M[11 * h * h], &M[h * h], &M[9 * h * h], h);      //M[11] = S4 = A12 - S2
        Sub(&M[12 * h * h], &M[5 * h * h], &M[4 * h * h], h);  //M[12] = S5 = B12 - B11
        Sub(&M[13 * h * h], &M[7 * h * h], &M[12 * h * h], h); //M[13] = S6 = B22 - S5
        Sub(&M[14 * h * h], &M[7 * h * h], &M[5 * h * h], h);  //M[14] = S7 = B22 - B12
        Sub(&M[15 * h * h], &M[13 * h * h], &M[6 * h * h], h); //M[15] = S8 = S6 - B21

        //16-22: P1 - P7: рекурсивный вызов себя же для умножения
        Mult(&M[16 * h * h], &M[9 * h * h], &M[13 * h * h], h);  //M[16] = P1 = S2 * S6
        Mult(&M[17 * h * h], &M[0], &M[4 * h * h], h);           //M[17] = P2 = A11 * B11
        Mult(&M[18 * h * h], &M[h * h], &M[6 * h * h], h);       //M[18] = P3 = A12 * B21
        Mult(&M[19 * h * h], &M[10 * h * h], &M[14 * h * h], h); //M[19] = P4 = S3 * S7
        Mult(&M[20 * h * h], &M[8 * h * h], &M[12 * h * h], h);  //M[20] = P5 = S1 * S5
        Mult(&M[21 * h * h], &M[11 * h * h], &M[7 * h * h], h);  //M[21] = P6 = S4 * B22
        Mult(&M[22 * h * h], &M[3 * h * h], &M[15 * h * h], h);  //M[22] = P7 = A22 * S8

        //23-24: T1, T2
        Add(&M[23 * h * h], &M[16 * h * h], &M[17 * h * h], h); //M[23] = T1 = P1 + P2
        Add(&M[24 * h * h], &M[23 * h * h], &M[19 * h * h], h); //M[24] = T2 = T1 + P4

        //25-28: четверти результирующей матрицы C
        Add(&M[25 * h * h], &M[17 * h * h], &M[18 * h * h], h); //M[25] = C11 = P2 + P3
        Add(&M[26 * h * h], &M[23 * h * h], &M[20 * h * h], h); //M[26] = C12 = T1 + P5
        Add(&M[26 * h * h], &M[26 * h * h], &M[21 * h * h], h); //M[26] = C12 += P6
        Sub(&M[27 * h * h], &M[24 * h * h], &M[22 * h * h], h); //M[27] = C21 = T2 - P7
        Add(&M[28 * h * h], &M[24 * h * h], &M[20 * h * h], h); //M[28] = C22 = T2 + P5

        //копируем результат
        Copyback(c, 0, 0, &M[25 * h * h], n); //C11 = M[25]
        Copyback(c, 0, h, &M[26 * h * h], n); //C12 = M[26]
        Copyback(c, h, 0, &M[27 * h * h], n); //C21 = M[27]
        Copyback(c, h, h, &M[28 * h * h], n); //C22 = M[28]

        delete[] M;
    }
}

void VinohradStrassen::Copy(double* a, double* b, size_t ib, size_t jb, size_t n)
{
    size_t imax = ib + n / 2;
    size_t jmax = jb + n / 2;

    for (size_t k = 0, i = ib; i < imax; i++)
    {
        for (size_t j = jb; j < jmax; j++)
        {
            a[k++] = b[i * n + j];
        }
    }
}

void VinohradStrassen::Copyback(double* a, size_t ia, size_t ja, double* b, size_t n)
{
    size_t imax = ia + n / 2;
    size_t jmax = ja + n / 2;

    for (size_t k = 0, i = ia; i < imax; i++)
    {
        for (size_t j = ja; j < jmax; j++)
        {
            a[i * n + j] = b[k++];
        }
    }
}

void VinohradStrassen::Add(double* c, double* a, double* b, size_t n)
{
    for (size_t i = 0; i < n * n; i++)
    {
        c[i] = a[i] + b[i];
    }
}

void VinohradStrassen::Sub(double* c, double* a, double* b, size_t n)
{
    for (size_t i = 0; i < n * n; i++)
    {
        c[i] = a[i] - b[i];
    }
}
