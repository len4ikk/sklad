#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

#include <iostream>

int main()
{
    setlocale(LC_ALL, "Russian");


	double v0 = 50.0; double g = 9.8; double dt = 1.0;
	double h,v ;
	int i;
	vector<double> times, velocities;
	for (double t = 0.0; ; t += dt)
	{
		h = v0 * t - 0.5 * g * t * t;
		if (h <= 0 && t > 0) {
			break;
		}
		else {
			v = v0  - g * t;
			velocities.push_back(v);
			times.push_back(t);
		}

	}

		cout << fixed << setprecision(2);

		cout << "|" << setw(10) << "t, c"
			<< "|" << setw(14) << "v, м/c" << "|" << endl;

		cout << "|" << setw(10) << "----------"
			<< "|" << setw(17) << "--------------" << "|" << endl;

		for (i = 0; i < (int)times.size(); i++)
		{
			cout << "|" << setw(10) << times[i]
				<< "|" << setw(17) << velocities[i] << "|" << endl;
		}
		cout << "после t = "<< times.back() <<" тело упало" << endl;
    return 0;
}
