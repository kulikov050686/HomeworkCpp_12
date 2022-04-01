#pragma once

/// <summary>
/// Класс реализующий алгоритм Винограда-Штрассена перемножения матриц
/// </summary>
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
	void MultStandart(double* c, double* a, double* b, size_t n);

	/// <summary>
	/// Умножение квадратных матриц по алгоритму Винограда - Штрассена
	/// </summary>
	/// <param name="c"> Результирующая матрица </param>
	/// <param name="a"> Первая матрица </param>
	/// <param name="b"> Вторая матрица </param>
	/// <param name="n"> Размер матриц </param>
	void Mult(double* c, double* a, double* b, size_t n);

	/// <summary>
	/// Запрет копирования
	/// </summary>	
	VinohradStrassen& operator = (const VinohradStrassen&) = delete;

	/// <summary>
	/// Запрат копирования
	/// </summary>	
	VinohradStrassen(const VinohradStrassen&) = delete;

	/// <summary>
	/// Деструктор
	/// </summary>
	virtual ~VinohradStrassen() = default;

private:

	void Copy(double* a, double* b, size_t ib, size_t jb, size_t n);

	void Copyback(double* a, size_t ia, size_t ja, double* b, size_t n);

	void Add(double* c, double* a, double* b, size_t n);

	void Sub(double* c, double* a, double* b, size_t n);
};
