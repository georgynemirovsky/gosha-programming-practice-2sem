#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int a, p = 1;
    cin >> a;
    for (int i = a / 2 + 1; i > 1; i--) {
        if (a % i == 0) {
            cout << i << " ";
        }
    }
    return 0;
}
