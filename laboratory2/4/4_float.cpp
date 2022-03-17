#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

float FMA(float psi[], float pdf[], float const dv, unsigned size)
{
    float sum = 0.0;
    for (int i = 0; i < size; i++)
    {
        sum = fma(psi[i], pdf[i], sum);
    }
    return fma(sum, dv, 0);
}
int main()
{
    float T = 0.f;
    cin >> T;
    long long int n = 1000000;
    float PI = acos(-1.0);
    float x = 0.f, dv = 0.f;
    if (T >= 1)
    {
        x = -T;
        dv = 2 * T / n;
    } else
    {
        x = -1 / sqrt(T);
        dv = 2 / sqrt(T) / n;
    }
    float *pdf = 0;
    float *psi = 0;
    psi = new float[n];
    pdf = new float[n];
    for (long long int i = 0; i < n; i++)
    {
        x = x + dv;
        psi[i] = abs(x);
        pdf[i] =exp(- x * x / T) / sqrt(PI * T);
    }
    cout << setprecision(10) << FMA(psi, pdf, dv, n) << endl;
    delete [] pdf;
    return 0;
}
