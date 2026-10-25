#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
#include <numeric>
#include <array>
using namespace std;

class Rocket {
    public:
        Rocket(double x = 0, double y = 0,
            double vx = 0, double vy = 0)
            : x(x), y(y), vx(vx), vy(vy) {}

        void updatePosition(double dt) {
            if (dt < 0.0) {
                cout << "приращение времени дложно быть положительным" << endl;
                return;
            }
            else {
                x+= vx * dt;
                y += vy * dt;
            }
        }

        void changeVelocity(double ax, double ay, double dt) {
            vx += ax * dt;
            vy += ay * dt;
            
        }

        double getX() const { return x; }
        double getY() const { return y; }
        double getVx() const { return vx; }
        double getVy() const { return vy; }

        void printState() const {
            cout << " коорд. х: " << x << ", коорд.y: " << y  << endl;
            cout << " скорость vx: " << vx<< ", скорость vy:  " << vy  << endl;
        }

    private:
        double x, y;       
        double vx, vy;   
    };

 
int main()
{
    setlocale(LC_ALL, "Russian");
    vector<Rocket> squad; 
    squad.reserve(5);
    vector<vector<array<double, 2>>> trajectories(5);


    squad.reserve(5);
    squad.emplace_back(1000, 10, 0, 50);
    squad.emplace_back(900, 15, -5, 40);
    squad.emplace_back(2000, 10, 100, 0);
    squad.emplace_back(500, 15, 10, 50);
    squad.emplace_back(100, 40, 40, 50);

    double T = 5.0;
    double dt = 0.5;
    double g = 9.8;

    for (size_t i = 0; i < squad.size(); ++i)
        trajectories[i].push_back({ squad[i].getX(), squad[i].getY() });

    for (double t = 0.0; t <= T; t += dt) {
        for (size_t i = 0; i < squad.size(); ++i) {
            squad[i].changeVelocity(0.0, -g, dt);
            squad[i].updatePosition(dt);
            trajectories[i].push_back({ squad[i].getX(), squad[i].getY() });
        }
    }
    for (size_t i = 0; i < squad.size(); ++i) {
        cout << "Ракета " << i + 1
            << ": x = " << squad[i].getX()
            << ", y = " << squad[i].getY() << endl;
   
        
    }


    return 0;

}

