#include <iostream>
using namespace std;

class AutonomousControl {
private:
    double altitude;
    double thrust;
    double targetAltitude;

public:
    AutonomousControl()
    {
        altitude = 0;
        thrust = 100;
        targetAltitude = 1000;
    }

    AutonomousControl(double h,
        double thrust1,
        double targetH)
    {
        altitude = h;
        thrust = thrust1;
        targetAltitude = targetH;
    }

    void updateControl() {
        if (altitude < targetAltitude)
            thrust += 1000;   
        else
            thrust -= 1000;  
    }

    void simulateStep(double dt) {
        altitude += (thrust / 500) * dt;
    }

    void printStatus() {
        cout << "Высота: " << altitude << "м, тяга: " << thrust << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    AutonomousControl ac(0, 2000, 20);
    for (int i = 0; i < 5; ++i) {
        ac.updateControl();
        ac.simulateStep(1.0);
        ac.printStatus();
    }

    return 0;
}