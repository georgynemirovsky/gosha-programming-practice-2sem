#include <iostream>

using namespace std;

struct Step {
    int value;
    int sum;
};


int minimal(int a, int b) {
    if (a > b) {
        return b;
    } else {
        return a;
    }
}


int main() {
    int n = 0;
    int a = 0;
    cin >> n;
    Step *steps = new Step[n];

    for (int i = 0; i < n; i++) {
        cin >> steps[i].value;
        steps[i].sum = 0;
    }

    if (n > 2) {
        steps[1].sum = abs(steps[0].value - steps[1].value);
        for (int i = 2; i < n; i++) {
            a = minimal(steps[i - 1].sum + abs(steps[i].value - steps[i - 1].value), steps[i - 2].sum + 3 * abs(steps[i].value - steps[i - 2].value));
            steps[i].sum = a;
        }
        cout << steps[n - 1].sum << endl;
    } else if (n == 1){
        cout << 0 << endl;
    } else {
        cout << abs(steps[0].value - steps[1].value) << endl;
    }
    return 0;
}
