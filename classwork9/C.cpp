#include <iostream>

using namespace std;

int main() {
    int length = 0;
    cin >> length;

    int tank_capacity = 0;
    cin >> tank_capacity;

    int nomber_of_refills = 0;
    cin >> nomber_of_refills;

    int *length_between_refill;

    length_between_refill = new int[nomber_of_refills + 1];
    for (int i = 0; i < nomber_of_refills; i++) {
        cin >> length_between_refill[i];
    }
    length_between_refill[nomber_of_refills] = length;

    bool flag = true;
    int now_cord = 0;
    int n = 0;

    for (int i = 0 ; i < nomber_of_refills; i++) {
        if (length_between_refill[i + 1] - length_between_refill[i] > tank_capacity) {
            flag = false;
            cout << -1 << endl;
        }
    }

    if (flag) {
        while (now_cord < length_between_refill[nomber_of_refills]) {
            for (int i = nomber_of_refills; i >= 0; i--) {
                if (now_cord + tank_capacity >= length_between_refill[i]) {
                    now_cord = length_between_refill[i];
                    n++;
                    break;
                }
            }
        }
        cout << n - 1 << endl;
    }
    delete [] length_between_refill;
    return 0;
}
