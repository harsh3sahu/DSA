#include <iostream>
using namespace std;
int main()
{
    int n = 5;
    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j <= n; j++)
        {
            if (j <= i)
                cout << j;
            else
                cout << "*";
        }
        for (int j = n; j >= 1; j--)
        {
            if (j <= i)
                cout << j;
            else
                cout << "*";
        }
        cout << endl;
    }
    return 0;
}
