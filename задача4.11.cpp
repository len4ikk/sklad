#include <iostream>
#include <iomanip>
using namespace std;

// ==================== Engine ====================
class Engine {

private:
    double thrust;
    double fuelFlow;
    double fuel;

public:
    Engine()
    {
        thrust = 0;
        fuelFlow = 0;
        fuel = 0;
    }
    Engine(double thrust1, double fuelFlow1, double fuel1)
    {
        thrust = thrust1;
        fuelFlow = fuelFlow1;
        fuel = fuel1;
    }


    double getThrust(){ 
        return thrust; }

    bool hasFuel(){ 
        bool fuelBool;
        if (fuel > 0) {
            fuelBool = true;
        }
        else {
            fuelBool = false;
        }
        return fuelBool;
    }

    void burn(double dt) {
        if (hasFuel() == true) {
            fuel -= fuelFlow * dt;
            if (fuel < 0) fuel = 0;
        }
    }

    double getFuel() { 
        return fuel; 
    }

};

// ==================== Navigation ====================
class Navigation {

private:
    double altitude;
    double velocity;
    double acceleration;
    double mass;

public:
    Navigation(double h, double v, double m)
    {
        altitude = h;
        velocity = v;
        mass = m;
        acceleration = 0;
    }

    Navigation()
    {
        altitude = 0;
        velocity = 0;
        acceleration = 0;
        mass = 100;

    }
    void update(double thrust, double dt) {
        acceleration = (thrust / mass) - 9.81;
        velocity += acceleration * dt;
        altitude += velocity * dt; 
    }

    void printStatus(double time) {
        cout << fixed << setprecision(2) ;
        cout << "t=" << time << "с"
            << " | h=" << altitude << "м"
            << " | v=" << velocity << "м/с"
            << " | a=" << acceleration << "м/с^2"<<endl;
    }

    double getAltitude()  { 
        return altitude; 
    }

};

// ==================== AutonomousFlightSystem ====================
class AutonomousFlightSystem {

private:
    Engine engine;
    Navigation nav;
    double time;

public:
    AutonomousFlightSystem(Engine engine1, Navigation nav1)
    {
        engine = engine1;
        nav = nav1;
        time = 0;
    }

    void simulate(double dt, double totalTime) {
        while (time < totalTime && engine.hasFuel()==true) {
            engine.burn(dt);
            nav.update(engine.getThrust(), dt);
            nav.printStatus(time);
            time += dt;
        }
        cout << "Полет завершен!"<<endl;
    }

    void printSummary() {
        cout << "Оставшееся топливо: " << engine.getFuel() << " кг"<<endl;
        cout << "Итоговая высота: " << nav.getAltitude() << " м" << endl;;
    }


};

// ==================== main ====================
int main() {
    setlocale(LC_ALL, "Russian");
    Engine engine(100000, 2000, 10000);
    Navigation nav(0.0, 0.0, 5000.0);
    AutonomousFlightSystem system(engine, nav);
    system.simulate(1.0, 5.0);
    system.printSummary();

    return 0;
}