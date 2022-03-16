#include <iostream>
#include <cmath>

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
    unsigned n = 100000;
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
    cout << mean(psi, pdf, dv, n) << endl;
    delete [] psi;
    delete [] pdf;
    return 0;
}
