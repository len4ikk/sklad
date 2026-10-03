
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	double L, ay, g,m;
	g = 9.81;
	cout << "введите подъеиную силу крыла(н): " << endl;
	cin >> L;
	cout << "введите массу(кг): " << endl;
	cin >> m;
	ay = (L - m * g) / m;
	if (ay < =0) {
		cout<<"режим снижения"<<endl;
	}
	if (ay >= 0.5) {
		cout << "режим набора высоты" << endl;
	}
	if (ay > 0 && ay<0.5) {
		cout << "режим горизонтального полета" << endl;
	}

	return 0;
}

