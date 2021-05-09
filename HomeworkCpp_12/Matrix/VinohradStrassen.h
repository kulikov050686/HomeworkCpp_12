#pragma once

class VinohradStrassen
{
protected:

	/// <summary>
	/// Стандартное умножение квадратных матриц
	/// </summary>
	/// <param name="c"> Результирующая матрица </param>
	/// <param name="a"> Первая матрица </param>
	/// <param name="b"> Вторая матрица </param>
	/// <param name="n"> Размер матриц </param>
	void mult_standart(double* c, double* a, double* b, int n);

	/// <summary>
	/// Умножение квадратных матриц по алгоритму Винограда - Штрассена
	/// </summary>
	/// <param name="c"> Результирующая матрица </param>
	/// <param name="a"> Первая матрица </param>
	/// <param name="b"> Вторая матрица </param>
	/// <param name="n"> Размер матриц </param>
	void mult(double* c, double* a, double* b, int n);

private:

	void copy(double* a, double* b, int ib, int jb, int n);

	void copyback(double* a, int ia, int ja, double* b, int n);

	void add(double* c, double* a, double* b, int n);

	void sub(double* c, double* a, double* b, int n);
};
