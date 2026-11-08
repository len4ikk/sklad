
#include <iostream>
using namespace std

class FlightComputer {
private:
    double altitude;
    double velocity;
    double fuel;
    double thrust;
    double t;

public:
    FlightComputer(double h, double v, double f, double th) {
        altitude = h;
        velocity = v;
        fuel = f;
        thrust = th;
        t = 0;
    }

    void simulateStep(double dt) {
        velocity += ((thrust / 1000.0) - 9.8) * dt;
        altitude += velocity * dt;
        fuel -= dt * 2;
        t += dt;
    }
    void printStatus() const {
        cout << "t=" << t << "с: "
            << "высота=" << altitude << "м, "
            << "скорость=" << velocity << "м/с, "
            << "топливо=" << fuel << endl;
    }
};


int main()
{
    setlocale(LC_ALL, "Russian");
    FlightComputer fc(0, 0, 100, 12000);
    for (int i = 0; i < 5; i++) {
        fc.simulateStep(0.5);
        fc.printStatus();
    }
    return 0;
}
