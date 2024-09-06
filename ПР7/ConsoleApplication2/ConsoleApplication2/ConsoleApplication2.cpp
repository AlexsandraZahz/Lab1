#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Функция для вычисления сплайна
double spline(double x, const vector<double> & x_v, const vector<double> & f_v) {
	int n = x_v.size();
	// Создание векторов для хранения промежуточных значений
	vector<double> a(n), b(n - 1), d(n - 1), h(n - 1);
	// Вычисление шага между узлами 
	for (int i = 0; i < n - 1; ++i) {
		h[i] = x_v[i + 1] - x_v[i];
	}
	// Вычисление коэффициентов a
	for (int i = 1; i < n - 1; ++i) {
		a[i] = 3 * (f_v[i + 1] - f_v[i]) / h[i] - 3 * (f_v[i] - f_v[i - 1]) / h[i - 1];
	}
	// Вычисление коэффициентов b,d
	for (int i = 0; i < n - 1; ++i) {
		if (i == 0) {
			b[i] = 2 * h[i];
			d[i] = a[i] / b[i];
		}
		else if (i == n - 2) {
			b[i] = 2 * h[i - 1] + 4 * h[i];
			d[i] = (a[i] - a[i - 1] * h[i - 1] / 2 - 3 * (f_v[i] - f_v[i - 1]) * h[i - 1] / h[i]) / b[i];
		}
		else {
			b[i] = 2 * (h[i - 1] + h[i]);
			d[i] = (a[i] - a[i - 1] * h[i - 1] / 2 - 3 * (f_v[i] - f_v[i - 1]) * h[i - 1] / h[i]) / b[i];
		}
	}
	// Обратный ход метода прогонки
	for (int i = n - 3; i >= 0; --i) {
		d[i] = (a[i] - h[i] * d[i + 1]) / (2 * h[i] + h[i + 1] * d[i + 1]);
	}



	// Определение интервала, в котором находится x
	int i = 0;
	while (x > x_v[i + 1]) {
		++i;
	}
	// Вычисление разности между x и узлом
	double dx = x - x_v[i];
	// Вычисление значения сплайна в точке x
	return f_v[i] + d[i] * dx + (3 * (f_v[i + 1] - f_v[i]) / h[i] - 2 * d[i] - d[i + 1]) * dx * dx / h[i] + (d[i] + d[i + 1] - 2 * (f_v[i + 1] - f_v[i]) / h[i]) * dx * dx * dx / (h[i] * h[i]);
}

// Задание точки, в которой нужно вычислить значение функции double x = ...
int main() {
	vector<double> x_v = { 1, 3, 5, 6 };
	vector<double> f_v = { 4, 3, 2, -3 };

	double x = 3;
	cout << "Значение функции в точке " << x << " равно " << spline(x, x_v, f_v) << endl;

	return 0;
}
