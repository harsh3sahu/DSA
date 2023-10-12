#include <iostream>
#include<math.h>
using namespace std;

int main()
{

    int n;
    cout << "enter a number\n";
    cin >> n;

    int x = n;
    int ans = 0;
    while (x != 1)
    {
        x = x / 2;
        ++ans;
    }
    

    if (n==pow(2, ans))
    {
        cout<< "true";
    }

    else
    {
        cout<< "false";
    }

    return 0;
}