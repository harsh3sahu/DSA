#include <iostream>
using namespace std;

int main()
{

    int a = 12, b = 6;
    int c=a&b;
    cout << c << endl;
    int d=a|b;
    int e= a^b;
    int f=~a;

    cout<<d<<endl<<e<<endl<<f<<endl;
    return 0;
}