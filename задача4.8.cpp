#include <iostream>
using namespace std;

class NavigationSystem {
private:
    double x, y;
    double velocityX, velocityY;
    bool gpsAvailable;

public:
    NavigationSystem(double x1, double y1, double vx, double vy, bool gpsAvailable1)
    {
        x = x1;
        y = y1;
        velocityX = vx;
        velocityY = vy;
        gpsAvailable = gpsAvailable1;

    }

    void integratePosition(double dt) {
        x += velocityX * dt;
        y += velocityY * dt;
    }

    void correctGPS(double realX, double realY) {
        if (gpsAvailable == false) {
            x = x;
            y = y;

        }
        else {
            x = (x + realX) / 2;
            y = (y + realY) / 2;
            cout << "Скорректированные координаты: (" << x << ", " << y << ")" << endl;
        }
       
    }

    void printPosition() {
        cout << "Координаты: (" << x << ", " << y << ")" << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    NavigationSystem nav(0, 0, 100, 50, true);
    nav.integratePosition(1);  
    nav.printPosition();
    nav.correctGPS(110, 60);       
    return 0;
}
