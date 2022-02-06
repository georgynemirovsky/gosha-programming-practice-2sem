#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int p = 1, n;
    cin >> n;
    if (n == 0) {
        cout << 1 << endl;
    } else {
        for (int i = 1; i < n + 1; i++) {
            p = p * i;
        }
        cout << p << endl;
    }
    return 0;
}
