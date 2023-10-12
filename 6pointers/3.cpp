#include <iostream>
using namespace std;

void update(int **p){
    // p=p+1;
    *p=*p+1;
    // **p=**p+1;
}

int main()
{

    int a = 23;
    int *p1 = &a;

    int **p2 = &p1;
    // int ***p3 = &p2;

   

    cout << a << endl;
    cout << *p1 << endl;
    cout << **p2 << endl;
    cout<<"after"<<endl;
     update(p2);
    cout << a << endl;
    cout << *p1 << endl;
    cout << *p2 << endl;




    // cout << a << endl;
    // cout << &a << endl;

    // cout << p1 << endl;
    // cout << *p1 << endl;

    // cout <<"before"<< **p2 << endl;
    //     cout << "after"<<**p2 << endl;

    // cout << "p2   "<<p2 << endl;

    // cout << p3 << endl;
    // cout << "p3   "<<*p3 << endl;

    return 0;
}