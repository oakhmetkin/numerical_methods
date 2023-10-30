﻿#pragma once

class Slae
{
public:
	Slae(int n);
	~Slae();

	// прочитать систему из файла
	virtual void read_slae_from_file(const char* filename);

	// распечатать расширенную матрицу системы
	void print_slae(bool format_on = false);

	// решить систему
	virtual void solve_slae() = 0;

	// распечатать решение
	virtual void print_solution();

	// для задания 3 (прибавить матрицу, умноженную на некоторый 10e-6 <= eps <= 10e-3)
	void add_mtx(double k);

protected:
	double** A = nullptr; // матрица системы
	double* x = nullptr; // столбец-решение системы
	double* y = nullptr; // столбец свободных членов системы
	int n = 0; // размер квадратной матрицы A

	// поменять i, j строчки местами
	void change_rows(int i, int j);

	// домножить i строчку на скаляр
	void multiply_row(int i, double alpha);

	// прибавить к i строчке j строчку, домжноженную на скаляр
	void add_row(int i, int j, double alpha);
};
