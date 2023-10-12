#include <iostream>
using namespace std;

int main()
{

    long long n;
    cout << "enter number" << endl;
    cin >> n;

    int i = 0;
    int count = 0;
    while (n!=0)
    {
        if (n & 1)
        {
            count++;
            
            
        }

       
            n=n >> 1;
        
        
    }
    cout << count;

    return 0;
}