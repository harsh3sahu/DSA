#include <iostream>
using namespace std;

int main()
{

    int n;
    cout << "enter a number\n";
    cin >> n;
    int ans = 0;
    int digit;
    while (n != 0)
    {

        digit = n % 10;

        ans = (ans * 10) + digit;
        n = n / 10;
    }



    if ((ans<INT_MAX)&&(ans>INT_MIN))
    cout << ans;

    else
    cout<<"0"; 

    return 0;
}