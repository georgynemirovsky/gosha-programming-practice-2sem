#include <iostream>

using namespace std;

int Fib(int n) {
    if (n == 1 or n == 2) {
        return 1;
    }
    if (n == 3) {
        return 2;
    }
    return Fib(n - 1) + Fib(n - 2) + Fib(n - 3);
}


int main() {
    int n = 0;
    cin >> n;
    cout << Fib(n + 1) << endl;
    return 0;
}
