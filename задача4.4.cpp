
#include <iostream>
using namespace std;

class Gyroscope {
private:
    double angularVelocity;
    bool calibrationRequired;

public:
    Gyroscope(double v, bool flag) {
        angularVelocity = v;
        calibrationRequired = flag;
    }
    void calibrate() {
        calibrationRequired = false;
    }
    void printStatus() {
         cout << "Скорость: " << angularVelocity << " °/с | Калибровка ";
        if (calibrationRequired) {
            cout << "требуется" << endl;
        }
        else {
            cout << "не требуется" << endl;;
        }
    }
};



int main()
{
    setlocale(LC_ALL, "Russian");
    Gyroscope g1(120.5, true);
    g1.printStatus();
    g1.calibrate();
    g1.printStatus();
    return 0;
}
