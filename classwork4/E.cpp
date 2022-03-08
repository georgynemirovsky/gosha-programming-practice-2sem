#include <iostream>

using namespace std;

void heapify(int* A, int n, int i)
{
    int indl = i;
    int indleft = 2 * i + 1;
    int indright = 2 * i + 2;
    if (indleft < n and A[indleft] > A[indl])
    {
        indl = indleft;
    }
    if (indright < n and A[indright] > A[indl])
    {
        indl = indright;
    }
    if (indl != i)
    {
        int t = A[indl];
        A[indl] = A[i];
        A[i] = t;
        heapify(A, n, indl);
    }
}

void heapsort(int *A, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(A, n, i);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        int t = A[0];
        A[0] = A[i];
        A[i] = t;
        heapify(A, i, 0);
    }
}
int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    heapsort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    delete [] arr;
    return 0;
}
