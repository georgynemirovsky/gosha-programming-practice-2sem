#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

float kahan_sum(float input[], int n) {
    float sum = 0.0;
    float c = 0.0;
    float y = 0.0, t = 0.0;
    for (int i = 0; i < n; ++i) {
        y = input[i] - c;
        t = sum + y;
        c = (t - sum) - y;
        sum = t;
    }
    return sum;
}
int main()
{
    float T = 0.f;
    cin >> T;
    long long int n = 1000;
    float PI = acos(-1.0);
    float x = 0.f, dv = 0.f;
    x = -5 * sqrt(T);
    dv = 10 * sqrt(T) / n;
    float *pdf = 0;
    pdf = new float[n];
    for (long long int i = 0; i < n; i++)
    {
        x = x + dv;
        pdf[i] = abs(x) * exp(- x * x / T) / sqrt(PI * T) * dv;
    }
    cout << setprecision(10) << kahan_sum(pdf, n) << endl;
    delete [] pdf;
    return 0;
}
