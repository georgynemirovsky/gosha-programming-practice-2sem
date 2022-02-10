#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n, a, b, c;
    b = 0;
    cin >> n >> a;
    c = a;
    for (int i = 1; i <= n; i++){
        b = 10 * b + (a % 10);
        a = a / 10;
    }
    if (b == c){
        cout << '\n' << endl;
    } else {
        cout << b << endl;
    }
    return 0;
}
