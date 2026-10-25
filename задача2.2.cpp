#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");

	double v0 = 50.0; double g = 9.8; double dt = 1.0;
	double h;
	int i;
	vector<double> times;
	vector<double> heights;
	for (double t = 0.0; ; t += dt)
	{
		h = v0 * t - 0.5 * g * t * t;
		if (h <= 0 && t > 0) {
			break;
		}
		if (t > 0) {                  
			times.push_back(t);
			heights.push_back(h);
		}
		}
	
	}
	if (heights.empty()) {
		cout << "нет данных о высотах" << endl;
	}
	else{
	

		cout << fixed << setprecision(2);

		cout << "|" << setw(10) << "t, c"
		<< "|" << setw(14) << "h, м" << "|" << endl;

		cout << "|" << setw(10) << "----------"
		<< "|" << setw(14) << "--------------" << "|" << endl;

		for (i = 0; i < (int)times.size(); i++)
		{
		cout << "|" << setw(10) << times[i]
			<< "|" << setw(14) << heights[i] << "|" << endl;
		}
	}
	size_t idx_max = 0; 
	for (size_t i = 1; i < heights.size(); ++i)
	{
		if (heights[i] > heights[idx_max]) { //возвращает первый максимум
			idx_max = i; 
		}
	}
	cout << "максимальная высота, м : "<< heights[idx_max] <<" время достижения этой высоты,с : " << times[idx_max] << endl;

	//второй способ
	auto it = max_element(heights.begin(), heights.end()); //возвращает первый максимум
	size_t idx = distance(heights.begin(), it);
	cout << "максимальная высота, м : " << *it << " время достижения этой высоты,с : " << times[idx] << endl;
    return 0;

}
