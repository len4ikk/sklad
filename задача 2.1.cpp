

#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
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
		if (h <= 0 && t>0) {
			break;
		}
		else {
			times.push_back(t); 
			heights.push_back(h);
		}

	}

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
	return 0;

}
