#include <iostream>
using namespace std;

int sum(int arr[], int n)
{
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        s = s + arr[i];
    }
    cout << *(arr+6)<< endl;
    return s;
}

int main()
{

    int arr[5] = {3, 54, 23, 46, 80};

    int ans = sum(arr, 5);
    cout << ans << endl;

    // char ch[6]="harsh";

    // cout<<ch<<endl;
    // cout<<ch[2]<<endl;

    // char *ptr=ch;

    // cout<<*(ptr)<<endl;

    // char c='f';
    // char *p=&c;

    // cout<<p<<endl;

    // char d='l';
    // char *p2=&d;
    // cout<<*(p2+1)<<endl;
    // cout<<&p<<endl<<&ptr<<endl;
    /*
    int x=9;
    int *ptr=&x;

    cout<<ptr<<endl;
    cout<<&ptr<<endl;
    cout<<*ptr<<endl;
    cout<<sizeof(ptr)<<endl;
    cout<<sizeof(x)<<endl;
    // cout<<*(*ptr)<<endl;
*/

    return 0;
}
