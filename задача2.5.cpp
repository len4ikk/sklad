#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
#include <numeric>
#include <array>
using namespace std;

#include <iostream>

int main()
{
    setlocale(LC_ALL, "Russian");
    double g = 9.8; double dt = 1.0;
    double h;
    vector<array<double, 3>> traj;
    double vx = 30, vy = 20, vz = 40;
    double t_max = 5;
    double x = 0, y = 0, z = 0;


    traj.push_back({ x,y,z });
    for (double t = 0; t <= t_max; t += dt) {
        vy = vy - g * dt;
        x += vx * dt;
        y += vy * dt;
        z += vz * dt;
        if (y < 0) { 
            cout << " тело уже упало после t= "<< t<<"c, (y<0)" << endl;
            break; 
        }
        else {
          
            traj.push_back({ x,y,z });
        }
    }
       cout << fixed << setprecision(2);
       cout << "|" << setw(8) << "t, c"
            << "|" << setw(10) << "x, м"
            << "|" << setw(10) << "y, м"
            << "|" << setw(10) << "z, м" << "|" << endl;
       cout << "|" << setw(8) << "--------"
            << "|" << setw(10) << "----------"
            << "|" << setw(10) << "----------"
            << "|" << setw(10) << "----------" << "|" << endl;
       
       double tt = 0;
       int i;
       for ( i = 0; i < (int)traj.size(); i++)
       {
           cout << "|" << setw(8) << tt
               << "|" << setw(10) << traj[i][0]
               << "|" << setw(10) << traj[i][1]
               << "|" << setw(10) << traj[i][2]
               << "|" << endl;
           tt += dt;
       }


    
    
    return 0;

}

