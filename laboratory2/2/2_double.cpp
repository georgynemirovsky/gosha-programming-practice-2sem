#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double mean(double pdf[], long long int nomber, long long int step)
{
    if (step >= nomber)
    {
        return pdf[0];
    }
    else
    {
        for (long long int i = 0; i < nomber; i += 2 * step)
        {
            if (i + step < nomber)
            {
                pdf[i] += pdf[i + step];
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
        return mean(pdf, nomber, step * 2);
    }
}
int main()
{
    double T = 0.f;
    cin >> T;
    long long int n = 10000000;
    double PI = acos(-1.0);
    double x = 0.f, dv = 0.f;
    x = -5 * sqrt(T);
    dv = 10 * sqrt(T) / n;
    double *pdf = 0;
    pdf = new double[n];
    for (long long int i = 0; i < n; i++)
    {
        x = x + dv;
        pdf[i] = abs(x) * exp(- x * x / T) / sqrt(PI * T) * dv;
    }
    cout << setprecision(10) << mean(pdf, n, 1) << endl;
    delete [] pdf;
    return 0;
}
