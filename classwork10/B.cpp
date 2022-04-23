#include <iostream>

using namespace std;

struct Element {
    int number = 0;
    int counts = 1;

    element () {
        number = 0;
        counts = 1;
    }
};

int minimal(int a, int b, int c) {
    if (a > b) {
        a = b;
    }
    if (a > c) {
        a = c;
    }
    return a;
}
int price (Element *steps, int n) {
    for (int i = 3; i < n; i++) {
        steps[i].counts += minimal(steps[i - 1].counts, steps[i - 2].counts, steps[i - 3].counts);
    }
    return steps[n - 1].counts;
}
int main() {
    int n = 0;
    cin >> n;
    Element *steps = new Element [n];
    for (int i = 0; i < n; i++) {
        steps[i].number = i + 1;
        cin >> steps[i].counts;
    }

    cout << price(steps, n) << endl;
    return 0;
}
