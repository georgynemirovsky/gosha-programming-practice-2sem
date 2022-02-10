#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n;
    float sum1 = 0;
    double sum2 = 0;
    cin >> n;
    for (double i = 1; i < n + 1; i++){
        sum1 = sum1 + (1/(i*i));
        sum2 = sum2 + (1/(i*i));
    }
    cout << sum1 << '\n' << sum2 << endl;
    //тип float не точен на больших n
    return 0;
}
