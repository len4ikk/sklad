
#include <iostream>
using namespace std;
class RocketStage {
private:
	double thrust; 
	double burnTime; 
	double mass;

public:
	RocketStage(double t, double b, double m) {
		thrust = t;
		burnTime = b;
		mass = m;
	}

	double getDeltaV(){
		if (mass == 0) { 
			double deltaV = 0;
			return deltaV; }
		else {
			double deltaV = (thrust * burnTime) / mass;
			return deltaV;
		}
		
	}

	void printInfo() {
		cout << "Тяга: " << thrust << " Н | "
			<< "Время: " << burnTime << " с | "
			<< "Масса: " << mass << " кг | "
			<< "DeltaV: " << getDeltaV() << " м/с" << endl;
	}
};
int main()
{
	setlocale(LC_ALL, "Russian");
	RocketStage s1(5000, 10, 1000);
	RocketStage s2(7000, 8, 900);
	RocketStage s3(9000, 6, 800);
	double totalV = s1.getDeltaV() + s2.getDeltaV() + s3.getDeltaV();
	cout << "Cкорость ракеты после срабатывания 1 ступени: " << s1.getDeltaV() << " м/с" << endl;
	cout << "Cкорость ракеты после срабатывания 2 ступени: " << s1.getDeltaV() + s2.getDeltaV() << " м/с" << endl;
	cout << "Итоговая скорость ракеты: " << totalV << " м/с"<<endl;
	return 0;
}
