
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    vector<double> rocket_heights = { 10, 20,35,40,30,40,20,50,60 };
    vector<double> rocket_times = { 0, 0.5, 1, 1.5, 2, 2.5, 3, 3.5, 4 };
    auto max_it = max_element(rocket_heights.begin(), rocket_heights.end());
    double max_height = *max_it;
    int time_ind = distance(rocket_heights.begin(), max_it);
    double time_max = rocket_times[time_ind]; 
    cout << "Максимальная достигнутая высота: " << max_height << " м" << endl;;
    cout << "Момент времени: " << time_max << " с" << endl;

    return 0;
}