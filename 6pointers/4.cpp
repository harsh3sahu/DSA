#include <iostream>
using namespace std;

int main()
{

    int arr[5] = {1, 2, 3, 4, 5};

    string name = "harsh";

    int *p1 = arr;
    string *p2 = &name;

    cout << *p1 << endl;
    cout << *p2 << endl;

    return 0;
}