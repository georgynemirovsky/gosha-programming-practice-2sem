#include <iostream>

using namespace std;

void update(int *mass, int ind, int sum, int n) {
    int *tmp;
    tmp = new int [n - 1];
    for (int i = 0; i < ind; i++) {
        tmp[i] = mass[i];
    }
    tmp[ind] = sum;
    for (int i = ind + 2; i < n; i++) {
        tmp[i - 1] = mass[i];
    }
    delete [] mass;
    mass = new int [n - 1];
    for (int i = 0; i < n - 1; i++) {
        mass[i] = tmp[i];
    }
    delete [] tmp;
}


int* cuts(int *mass, int n) {
    int *tmp = new int [n - 1];
    for (int i = 0; i < n - 1; i++) {
        tmp[i] = mass[i + 1] - mass[i];
    }
    return tmp;
}


int minimal_fee(int *mass, int n) {
    int fee = 0;
    int min_ind = 0;
    int min_sum = mass[0] + mass[1];
    while (n > 1) {
        for (int i = 0; i < n - 1; i++) {
                if (min_sum > mass[i] + mass[i + 1]) {
                    min_sum = mass[i] + mass[i + 1];
                    min_ind = i;
                }
            }
        update(mass, min_ind, min_sum, n);
        n--;
        fee += min_sum;
        min_ind = 0;
        min_sum = mass[0] + mass[1];
    }
    return fee;
}


int main() {
    int len = 0;
    cin >> len;
    int n = 0;
    cin >> n;
    int *mass;
    mass = new int [n + 2];
    for (int i = 1; i < n + 1; i++) {
        cin >> mass[i];
    }
    mass[0] = 0;
    mass[n + 1] = len;

    int *mass_len = cuts(mass, n + 2);
    cout << minimal_fee(mass_len, n + 1) << endl;
    delete [] mass;
    return 0;
}
