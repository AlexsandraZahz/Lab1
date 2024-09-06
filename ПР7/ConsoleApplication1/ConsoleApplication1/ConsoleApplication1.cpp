#include <iostream>
#include <vector>

using namespace std;

double lagrange(vector<double> x, vector<double> y, double x_val) {
	double result = 0.0;
	for (int i = 0; i < x.size(); i++) {
		double term = y[i];
		for (int j = 0; j < x.size(); j++) {
			if (j != i) {
				term *= (x_val - x[j]) / (x[i] - x[j]);
			}
		}
		result += term;
	}
	return result;
}

int main() {
	vector<double> x = { 1, 3, 5, 6 };
	vector<double> y = { 4, 3, 2, -3 };
	double x_val = 2;
	double result = lagrange(x, y, x_val);
	cout << "Значение интерполяционного многочлена в точке " << x_val << " равно " << result << endl;
	return 0;
}
