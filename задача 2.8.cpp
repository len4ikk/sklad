#include <iostream>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	int i;
	double t_fall1, t_fall2;
	vector<double> heights1 = { 1, 1.5, 5.2, 9.9, 10.0, 12.3, 25.7, 8.4, 30.1 };
	vector<double> times1 = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
	vector<double> heights2 = { 0, 1, 2.5, 3.2, 9, 8, 5, 0, -2, -3};
	vector<double> times2 = { 0, 1, 2, 3, 4, 5, 6, 7, 8};

	auto max1 = max_element(heights1.begin(), heights1.end());
	size_t idx_max1 = distance(heights1.begin(), max1); 
	double t_max1 = times1[idx_max1];

	auto max2 = max_element(heights2.begin(), heights2.end());
	size_t idx_max2 = distance(heights2.begin(), max2);
	double t_max2 = times2[idx_max2];

	auto it1 = find_if(heights1.begin()+1, heights1.end(), [](double h) { return h <=
		0.0; });
	if (it1 == heights1.end()) {
		cout << "1 самолет: падения не было" << endl;
		t_fall1 = 10000000;
	}
	else {
		size_t idx = distance(heights1.begin(), it1);
		t_fall1 = times1[idx];
	}

	auto it2 = find_if(heights2.begin()+1, heights2.end(), [](double h) { return h <=
		0.0; });
	if (it2 == heights2.end()) {
		cout << "2 самолет: падения не было" << endl;
		t_fall2 = 10000000;
	}
	else {
		size_t idx = distance(heights2.begin(), it2);
		t_fall2 = times2[idx];
	}

	if (*max1 > *max2) {
		cout << "первый самолет поднялся выше" << endl;
	}
	 else if (*max1 < *max2) {
		cout << "втрой самолет поднялся выше" << endl;
	}
		else { cout << "у самолетов одинаковаая масксимальная высота" << endl; }



	if (t_fall1 > t_fall2) {
		cout << "первый самолет дольше находился в воздхе" << endl;
	}
	else if (t_fall1 < t_fall2) {
		cout << "втрой самолет дольше находился в воздхе" << endl;
	}
	else { cout << "самолеты одинаковое время находились в воздухе" << endl; }

	cout << fixed << setprecision(2);
	cout<< "|" << setw(14) << "Параметр"<< "|" << setw(11) << "Самолёт 1"<< "|" << setw(11) << "Самолёт 2" << "|" << endl;
	cout << "----------------------------------------" << endl;
	cout << "|" << setw(14) << "max_height" << "|" << setw(11) << *max1 << "|" << setw(11) << *max2 << "|" << endl;
	cout << "----------------------------------------" << endl;
	cout << "|" << setw(14) << "time_of_max" << "|" << setw(11) << t_max1 << "|" << setw(11) << t_max2 << "|" << endl;
	cout << "----------------------------------------" << endl;
	cout << "|" << setw(14) << "time_of_fall"<< "|";
	if  (t_fall1 == 10000000) {cout << setw(11) << "нет" << "|"; }
	else { cout << setw(11) << t_fall1; }
	if  (t_fall2 == 10000000) {cout << setw(11) << "нет" << "|"; }
	else { cout << setw(11) << t_fall2; }

	return 0;

}
