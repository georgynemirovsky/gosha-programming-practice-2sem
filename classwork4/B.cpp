#include <iostream>

using namespace std;

int main()
{
    int SIZE;
    cin >> SIZE;
    int *arr = new int[SIZE];
    for (int i = 0; i < SIZE; i++){
        cin >> arr[i];
    }

    for (int i = 0; i < SIZE; i++){
        cout << *(arr+i) << " ";
    }

    cout << endl;

    for (int i = SIZE - 1; i >= 0; i--){
        cout << *(arr+i) << " ";
    }

    delete [] arr;
    return 0;
}
