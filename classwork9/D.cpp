#include <iostream>

using namespace std;

struct denom_array_t {
    unsigned int *arr;
    unsigned int sz;
    denom_array_t() {
        arr = nullptr;
        sz = 0;
    }


    void append(unsigned int value) {
        sz++;
        if (arr == nullptr) {
            arr = new unsigned int[1];
            arr[0] = value;
        } else {
            unsigned int *tmp;
            tmp = new unsigned int[sz];
            for (int i = 0; i < sz - 1; i++) {
                tmp[i] = arr[i];
            }
            delete [] arr;
            tmp[sz - 1] = value;
            arr = nullptr;
            arr = tmp;
            delete [] tmp;
            tmp = nullptr;
        }
    }


    void print() {
        for (int i = 0; i < sz; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};


void reduction (unsigned int &num, unsigned int &den) {
    for (int i = num; i >= 2; i--) {
        if (num % i == 0 and den % i == 0) {
            num = num / i;
            den = den / i;
            return;
        }
    }
}


denom_array_t egyptian_fractions(unsigned int num, unsigned int den) {
    denom_array_t den_s;
    int i = 1;
    unsigned int new_num = 0;
    unsigned int new_den = 0;
    while (num != 1) {
        i = 1;
        while (num * i < den) {
            i++;
        }
        new_den = i * den;
        new_num = i * num - den;
        num = new_num;
        den = new_den;
        reduction(num, den);
        den_s.append(i);
    }
    den_s.append(den);
    return den_s;
}


int main() {
    denom_array_t t;
    unsigned int numerator = 0;
    unsigned int denominator = 0;
    cin >> numerator >> denominator;
    reduction(numerator, denominator);
    t = egyptian_fractions(numerator, denominator);
    t.print();
    return 0;
}
