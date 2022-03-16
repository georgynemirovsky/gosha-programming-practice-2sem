#include <iostream>
#include <cmath>

using namespace std;

double kahan_sum(double input[], int n) {
    double sum = 0.0;
    double c = 0.0;
    double y = 0.0, t = 0.0;
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
    double T = 0.f;
    cin >> T;
    long long int n = 1000;
    double PI = acos(-1.0);
    double x = 0.f, dv = 0.f;
    if (T >= 1)
    {
        x = -T;
        dv = 2 * T / n;
    } else
    {
        x = -1 / sqrt(T);
        dv = 2 / sqrt(T) / n;
    }
    double *pdf = 0;
    pdf = new double[n];
    for (long long int i = 0; i < n; i++)
    {
        x = x + dv;
        pdf[i] = abs(x) * exp(- x * x / T) / sqrt(PI * T) * dv;
    }
    cout << kahan_sum(pdf, n) << endl;
    delete [] pdf;
    return 0;
}
