#include <iostream>
#include <vector>

using namespace std;

int part(vector<int> &A, int lo, int hi) {
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

void quicksort(vector<int> &A, int lo, int hi) {
    if (lo < hi) {
        int p = part(A, lo, hi);
        quicksort(A, lo, p);
        quicksort(A, p + 1, hi);
    }
}

int minimal(int a, int b) {
    if (a > b) {
        return b;
    } else {
        return a;
    }
}

int main()
{
    int number = 0;
    int s = 0;
    vector<int> arr;
    vector<int> length;
    while (cin >> number) {
        arr.push_back(number);
    }

    quicksort(arr, 0, arr.size() - 1);

    if (arr.size() == 2) {
        cout << arr[1] - arr[0] << endl;
        return 0;
    }
    length.push_back(arr[1] - arr[0]);
    length.push_back(arr[2] - arr[0]);
    for (int i = 2; i < arr.size() - 1; i++) {
        length.push_back(minimal(length[i - 1], length[i - 2]) + arr[i + 1] - arr[i]);
    }

    cout << length[length.size() - 1] << endl;
    return 0;
}
