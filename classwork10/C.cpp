#include <iostream>

using namespace std;

struct integer {
    int number;
    int counts;

    integer () {
        number = 0;
        counts = 1;
    }
};


int th (integer* mass, int n) {
    int i = 0;
    int j = 1;
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < j; i++) {
            if (mass[i].number < mass[j].number and mass[j].counts <= mass[i].counts) {
                mass[j].counts++;
            }
        }
    }
    int m = 0;
    for (int i = 0; i < n; i++) {
        if (m < mass[i].counts) {
            m = mass[i].counts;
        }
    }
    return m;
}
int main() {
    int n = 0;
    cin >> n;
    integer *mass = new integer [n];

    for (int i = 0; i < n; i++) {
        cin >> mass[i].number;
    }

    cout << th(mass, n) << endl;
    return 0;
}
