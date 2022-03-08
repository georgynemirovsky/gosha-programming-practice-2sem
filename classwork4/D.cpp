#include <iostream>

using namespace std;

int part(int* A, int lo, int hi) {
    int pivot = A[(hi + lo) / 2];
    int i = lo;
    int j = hi;
    while (true) {
        while (A[i] < pivot) {
            i++;
        }
        while (A[j] > pivot) {
            j--;
        }
        if (i >= j) {
            return j;
        }
        int t = A[i];
        A[i] = A[j];
        A[j] = t;
        i++;
        j--;
    }
}

void quicksort(int* A, int lo, int hi)
{
    if (lo < hi) {
        int p = part(A, lo, hi);
        quicksort(A, lo, p);
        quicksort(A, p + 1, hi);
    }
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    quicksort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    delete [] arr;
    return 0;
}
