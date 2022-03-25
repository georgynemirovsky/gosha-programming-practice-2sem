#include <iostream>
#include <string.h>

using namespace std;
struct dot
{
    int x1, x2;
};
void order(dot & a)
{

    if (a.x2 < a.x1)
    {
        int t = a.x1;
        a.x1 = a.x2;
        a.x2 = t;
    }
}
int part(dot* A, int lo, int hi)
{
    int pivot = A[(hi + lo) / 2].x1;
    int i = lo;
    int j = hi;
    while (true)
    {
        while (A[i].x1 < pivot)
        {
            i++;
        }
        while (A[j].x1 > pivot)
        {
            j--;
        }
        if (i >= j)
        {
            return j;
        }
        dot t = A[i];
        A[i] = A[j];
        A[j] = t;
        i++;
        j--;
    }
}

void quicksort(dot* A, int lo, int hi)
{
    if (lo < hi) {
        int p = part(A, lo, hi);
        quicksort(A, lo, p);
        quicksort(A, p + 1, hi);
    }
}
bool dot_in(int x1, int x2, int x3)
{
    if ((x1 <= x3) and (x3 <= x2))
    {
        return true;
    } else
    {
        return false;
    }
}

int main()
{
    int n = 0;
    bool flag = true;
    cin >> n;
    dot *d = new dot[n];
    for (int i = 0; i < n; i++)
    {
        cin >> d[i].x1 >> d[i].x2;
        order(d[i]);
    }
    quicksort(d, 0, n - 1);
    for (int i = 0; i < n - 1; i++)
    {
        if (not(dot_in(d[i].x1, d[i].x2, d[n-1].x1)))
        {
            flag = false;
            break;
        }
    }
    if (flag)
    {
        cout << "YES" << endl;
    } else
    {
        cout << "NO" << endl;
    }
    delete [] d;
    return 0;
}
