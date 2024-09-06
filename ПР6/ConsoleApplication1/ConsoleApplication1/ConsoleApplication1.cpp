#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

void swap_row(double matrix[4][4], int i, int j, int n) {
	for (int k = 0; k < n; k++) {
		double temp = matrix[i][k];
		matrix[i][k] = matrix[j][k];
		matrix[j][k] = temp;
	}
}

double determinant(double matrix[4][4], int n) {
	double det = 1;
	for (int i = 0; i < n; i++) {
		int index = i;
		for (int j = i + 1; j < n; j++)
			if (abs(matrix[j][i]) > abs(matrix[index][i]))
				index = j;
		if (index != i) {
			swap_row(matrix, index, i, n);
			det = det * pow(-1, index - i);
		}
		if (matrix[i][i] == 0) {
			det = 0;
			break;
		}
		for (int j = i + 1; j < n; j++) {
			double temp = matrix[j][i] / matrix[i][i];
			for (int k = i; k < n; k++)
				matrix[j][k] -= temp * matrix[i][k];
		}
	}
	for (int i = 0; i < n; i++)
		det *= matrix[i][i];
	return det;
}

int main() {
	int n = 4;
	double matrix[4][4] = {
		{-1.6, 5.4, -7.7, 3.1},
		{8.2, 1.4, -2.3, 0.2},
		{5.3, -5.9, 2.7, -7.9},
		{0.7, 1.9, -8.5, 4.8}
	};
	cout << "Определитель матрицы: " << fixed << setprecision(3) << determinant(matrix, n) << endl;
	return 0;
}