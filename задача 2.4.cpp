#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;


int main()
{
    
    setlocale(LC_ALL, "Russian");
	double v0 = 50.0; double g = 9.8; double dt = 1.0;
	double h, v;
	int i;
	vector<double> times, velocities;
	double t_fall = 2 * v0 / g;
	for (double t = 0.0; t < t_fall; t+=dt)
	{
		h = v0 * t - 0.5 * g * t * t;
		if (h <= 0 && t > 0) {
			break;
		}
		else {
			v = v0 - g * t;
			velocities.push_back(v);
			times.push_back(t);
		}

	}
	double sum = accumulate(velocities.begin(), velocities.end(), 0.0); //первый вариант
	double avg = sum / velocities.size();
	cout << fixed << setprecision(3);
	cout << "средняя скорость за весь полет: 1-ый вариант :  " << avg << endl;

	double sum_abs = 0.0; //второй вариант
	for (i = 0; i <(int)velocities.size(); i++)
		sum_abs += fabs(velocities[i]);
	double avg_abs = sum_abs /velocities.size();
	cout << fixed << setprecision(3);
	cout << "средняя скорость за весь полет: 2-ый вариант :  " << avg_abs << endl;



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
	cout << fixed << setprecision(2);
	cout << "после t = " << t_fall << " тело уже упало" << endl;

    return 0;

}

