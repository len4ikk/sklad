#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class DroneFlight {

private:
    vector<double> x , y ;
    double totalDistance ;


public:
    DroneFlight() {
        x.push_back(0);
        y.push_back(0);
        totalDistance = 0;
    }

    void addPoint(double newX, double newY) {
        totalDistance += sqrt( ((x.back()-newX)* (x.back() - newX)) + ((y.back() - newY) * (y.back() - newY)));
        x.push_back(newX);
        y.push_back(newY);
    }

    double getTotalDistance() { 
        return totalDistance; 
    }

    void printPath() {
        cout << "Точки маршрута:"<<endl;
        for (size_t i = 0; i < x .size(); ++i) {
            cout << "(" << x[i] << ", " << y[i] << ")" << endl;;
        }
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    DroneFlight d;
    d.addPoint(0, 0);
    d.addPoint(3, 4);
    d.addPoint(6, 8);
    d.printPath();
    cout << "Пройдено: " << d.getTotalDistance() << " м"<<endl;
}