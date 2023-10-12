#include <iostream>
#include <cstring>

using namespace std;

class nQueue
{

public:
    int size;
    int n;
    int *front;
    int *rear;
    int *arr;
    int *next;
    int freespace;

    nQueue(int size, int n)
    {
        this->size = size;
        this->n = n;
        freespace=0;
        front = new int[n];
        rear = new int[n];
        memset(front, -1, n*sizeof(int));
        memset(rear, -1, n*sizeof(int));

        next = new int[size];
        for (int i = 0; i < size; i++)
        {
            next[i] = i + 1;
        }
        next[size - 1] = -1;

        arr = new int[size];
        memset(arr, 0, size*sizeof(int));

    
    }

    void push(int data, int nq)
    {
        
        int index = freespace;
        freespace = next[index];

        if (front[nq - 1] == -1)
        {
            front[nq - 1] = index;
        }

        else
        {
            next[rear[nq - 1]] = index;
        }

        next[index] = -1;
        rear[nq - 1] = index;
        arr[index] = data;
    }

    void pop(int nq){
        int index=front[nq-1];
        front[nq-1]=next[index];
        next[index]=-1;

        arr[index]=0;
    }

    void print(int nq){
        int index=front[nq-1];
        while(index!=rear[nq-1]){
            cout<<arr[index]<<endl;
            index=next[index];
        }
        cout<<arr[rear[nq-1]];
    }
};

int main()
{

    nQueue k(9, 3);

    k.push(10, 1);
    k.push(20, 1);
    k.push(50, 2);
    k.push(100, 3);
    k.push(60, 2);
    k.push(90,2);
    // k.pop(2);
    // k.pop(2);

    k.print(2);

    return 0;
}