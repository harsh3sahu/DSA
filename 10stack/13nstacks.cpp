#include <iostream>
#include <cstring>
using namespace std;

class Nstack
{

public:
    int *arr;
    int size;
    int *top;
    int *next;
    int freespace = 0;

    Nstack(int size, int s)
    {
        this->size = size;
        arr = new int[size];
        top= new int [s];
        next=new int[size];
        memset(arr, 0, size);

        memset(top, -1, size);

        for (int i = 0; i < size; i++)
        {
            if (i < size - 1)
            {
                next[i] = i + 1;
            }

            else
            {
                next[i] = -1;
            }
        }
    }

    void push(int n, int s)
    {
        int index = freespace;

        freespace = next[index];

        arr[index] = n;

        next[index] = top[s-1];

        top[s - 1] = index;
    }

    void pop(int s)
    {
        int index = top[s - 1];

        arr[index] = 0;

        top[s - 1] = next[index];

        next[index] = freespace;

        freespace = index;
    }

    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << endl;
        }
    }
};

int main()
{

    Nstack st(6,3);

    st.push(10, 1);
    st.push(20, 1);
    st.push(30, 1);
    st.push(45, 2);
    st.push(30, 1);
    st.push(60,3);

    st.print();
    // st.pop(3);
    st.pop(1);
    st.pop(1);
    st.print();

  

    return 0;
}