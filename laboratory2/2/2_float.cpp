#include <iostream>
#include <cmath>

using namespace std;

float mean(float pdf[], long long int nomber, long long int step)
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
    float T = 0.f;
    cin >> T;
    long long int n = 1000;
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
    pdf = new float[n];
    for (long long int i = 0; i < n; i++)
    {
        x = x + dv;
        pdf[i] = abs(x) * exp(- x * x / T) / sqrt(PI * T) * dv;
    }
    cout << mean(pdf, n, 1) << endl;
    delete [] pdf;
    return 0;
}
