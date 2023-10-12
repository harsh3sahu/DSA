#include <iostream>
using namespace std;

int main()
{

    int n;
    cout << "enter a number \n";
    cin >> n;

    int rem = 1;
    int p = 1, s = 0;
  

    while (n != 0)
    {

        rem = n % 10;

        p = p * rem;
        s = s + rem;

        n = n / 10;
    }

    cout << "product =" << p << endl
         << "sum=" << s << endl;

    return 0;
}