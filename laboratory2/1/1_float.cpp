#include <iostream>
#include <cmath>
#include<iomanip>

using namespace std;

float mean(float const psi[], float const pdf[], float const dv, unsigned nomber)
{
    if (nomber == 1)
    {
        return psi[0] * pdf[0] * dv;
    } else
    {
        return mean(psi, pdf, dv, nomber / 2) + mean(psi + nomber / 2, pdf + nomber / 2, dv, nomber - nomber /  2);
    }
}
int main()
{
    float T = 0.f;
    cin >> T;
    unsigned n = 10000000;
    float PI = M_PI;  // acos(-1.0);
    float x = 0.f, dv = 0.f;
    x = -5 * sqrt(T);
    dv = 10 * sqrt(T) / n;
    float *psi = 0;
    float *pdf = 0;
    psi = new float[n];
    pdf = new float[n];
    for (long long int i = 0; i < n; i++)
    {
        x = x + dv;
        psi[i] = abs(x);
        pdf[i] = exp(- x * x / T) / sqrt(PI * T);
    }
    cout << setprecision(10) << mean(psi, pdf, dv, n) << endl;
    delete [] psi;
    delete [] pdf;
    return 0;
}
