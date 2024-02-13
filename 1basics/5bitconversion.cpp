#include <iostream>
#include<math.h>
using namespace std;

int main()
{

    int n;
    cout << "enter a number" << endl;
    cin >> n;

    int ans = 0;
    
    while (n != 0)
    {

        int bit = n & 1;

        ans = (ans *10) + bit;
        
        n=n >> 1;
    }

    cout<<endl<<ans;

    return 0;
}