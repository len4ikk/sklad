

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    setlocale(LC_ALL, "Russian");
    vector<int> sensor = { 2, 5, 0, 4, 0, 0, 7, 8, 0, 3, 1, 0 };
    int zero_count = count(sensor.begin(), sensor.end(), 0);
    cout << "Количество нулевых показаний датчика: " << zero_count << endl;;

    return 0;
}