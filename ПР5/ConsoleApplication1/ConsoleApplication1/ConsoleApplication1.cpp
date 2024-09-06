#include <iostream> 
#include <vector> 
#include <stdio.h>
#include <iomanip>

using namespace std;

vector<double> solveSystem(vector<vector<double>> A, vector<double> B) {
	int n = A.size();

	// Подготовка расширенной матрицы 
	for (int i = 0; i < n; i++) {
		A[i].push_back(B[i]);
	}

	// Приведение системы к треугольному виду 
	for (int i = 0; i < n; i++) {
		// Поиск главного элемента в столбце 
		double maxElement = abs(A[i][i]);
		int maxIndex = i;
		for (int k = i + 1; k < n; k++) {
			if (abs(A[k][i]) > maxElement) {
				maxElement = abs(A[k][i]);
				maxIndex = k;
			}
		}

		// Приведение строки к треугольному виду 
		for (int k = i + 1; k < n; k++) {
			double koff = -A[k][i] / A[i][i];
			for (int j = i; j <= n; j++) {
				A[k][j] += koff * A[i][j];
			}
		}
	}

	// Обратный ход метода Гаусса 
	vector<double> X(n);
	for (int i = n - 1; i >= 0; i--) {
		X[i] = A[i][n] / A[i][i];
		for (int j = i - 1; j >= 0; j--) {
			A[j][n] -= A[j][i] * X[i];
		}
	}

	return X;
}

int main() {

	// Система уравнений: 
	// 0,61x + 0,71y - 0,05z = 0,44 
	// -1,03x - 2,05y + 0,87z = -1,16 
	// 2,5x - 3,12y - 5,03z = -7,5 

	setlocale(LC_ALL, "Russian");
	vector<vector<double>> A = { {0.61, 0.71, -0.05}, {-1.03, -2.05, 0.87}, {2.5, -3.12, -5.03} };
	vector<double> B = { 0.44, -1.16, -7.5 };

	vector<double> X = solveSystem(A, B);

	cout << "Решение системы:" << endl;
	cout << "x = " << fixed << setprecision(4) << X[0] << endl;
	cout << "y = " << fixed << setprecision(4) << X[1] << endl;
	cout << "z = " << fixed << setprecision(4) << X[2] << endl;

	getchar();
	return 0;
}