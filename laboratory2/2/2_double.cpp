#include <iostream>
#include <cmath>

using namespace std;

double mean(double pdf[], long long int nomber)
{
    static long long int nom = 1;
    while (nom < nomber)
    {
        for (long long int i = 0; i < nomber; i += 2 * nom)
        {
            if (i + nom < nomber)
            {
                pdf[i] += pdf[i + nom];
            }
            else
            {
                int j = 1;
                while (i + j < nomber)
                {
                    pdf[i] += pdf[i + j];
                    j++;
                }
            }
        }
        nom *= 2;
    }
    return pdf[0];
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
    cout << mean(pdf, n) << endl;
    delete [] pdf;
    return 0;
}
