#include <iostream>

using namespace std;

void counter()
{
    static int nom = 0;
    nom++;
    cout << nom <<endl;
}
int main()
{
    for (int i = 1; i <= 10; i++){
        counter();
    }
    return 0;
}
