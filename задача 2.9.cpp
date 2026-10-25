#include <iostream>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	vector<double> h{ 1, 2.2, 5, 7, 8.9, 5, 3, 1, -1, -2 };
	vector<double> smoothed(h.size());
	size_t n = h.size();
	smoothed[0] = (h[0] + h[1]) / 2.0;
	smoothed[n - 1] = (h[n - 2] + h[n - 1]) / 2.0;

	for (size_t i = 1; i < h.size()-1; ++i) {
		double rand_noise = (rand() % 200) / 100.0 - 1.0;
		h[i] += rand_noise;
	}
	for (size_t i = 1; i + 1 < (int)h.size(); ++i) {
		smoothed[i] = (h[i - 1] + h[i] + h[i + 1]) / 3.0;
	}

	cout << fixed << setprecision(2);
	cout << "----------------------------------" << endl;
	cout << "|" << setw(10) << "Исходный" << " |" << setw(12) << "Сглаженный" << " |" << endl;
	cout << "----------------------------------" << endl;

	for (size_t i = 0; i < n; ++i) {
		cout << "|" << setw(10) << h[i] << " |" << setw(12) << smoothed[i] << " |" << endl;
	}
	cout << "----------------------------------" << endl;


	return 0;
}

