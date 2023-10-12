#include <iostream>
using namespace std;

int fib(int n)
{

    int ans = 0;

    if (n == 1 || n == 0)
    {
        return n;
    }
    
    return fib(n - 1) + fib(n - 2);

  
}

int main()
{

    int a;
    cout << "enter a number\n";
    cin >> a;

    int ans=fib(a);
    cout<<ans;
    return 0;
}