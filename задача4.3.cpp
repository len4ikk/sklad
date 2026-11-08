
#include <iostream>
using namespace std;

class Engine {
private:
    double thrust;
    double fuelFlow;

public:
    Engine(double T, double F) {
        thrust = T;
        fuelFlow = F;
    }
    double getSpecificImpulse() {
        if (fuelFlow == 0) {
            double Impulse = 0;
            return Impulse;
        }
        else{
            double Impulse = thrust / (fuelFlow * 9.81);
            return Impulse;
                
        }
        
    }
    void printInfo() {
        cout << "Тяга: " << thrust << " Н | "
            << "Расход: " << fuelFlow << " кг/с | "
            << "Удельный импульс: " << getSpecificImpulse() << " с"
            << endl;
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    Engine e1(5000, 2.5);
    e1.printInfo();
    return 0;
}
