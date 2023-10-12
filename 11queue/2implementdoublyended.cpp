#include <iostream>
#include <cstring>

using namespace std;

class dQueue
{

public:
    int *arr;
    int front = -1;
    int rear = -1;
    int size;

    dQueue(int size)
    {
        this->size = size;
        arr = new int[size];
        cout << size << " this is size of array\n";
        memset(arr, -1, size);
    }

    void push_front(int data)
    {
        if (front == -1 && rear == -1)
        {
            front = rear = 0;
            arr[front] = data;
            // front = size - 1;
            // rear++;
        }

        else if (front > 0 && front < size && front-1 != rear)
        {
            front--;
            arr[front] = data;
            
        }

        else if (front == 0)
        {
            front = size - 1;
            arr[front] = data;
            
        }
    }

    void push_back(int data)
    {

        if (front == -1 && rear == -1)
        {
            front = rear = 0;

            arr[rear] = data;
            
        }

        else if (rear >= 0 && rear < size - 1 && rear+1 != front)
        {
            rear++;
            arr[rear] = data;
           
        }

        else if (rear == size - 1 && front != 0 && front != rear)
        {
            rear = 0;
            arr[rear] = data;
            rear++;
        }
    }

    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << endl;
        }
    }

    void pop_front()
    {
        if (front == rear)
        {
            cout << "queue empty";
        }

        else
        {
            arr[front] = -1;
            front++;

            if (front >= size && front != rear)
            {
                front = 0;
            }

            else if (front >= size && front == rear)
            {
                cout << "queue overflow\n";
            }
        }
    }

    void pop_back()
    {
        if (rear > 0 && rear < size - 1 && front != rear)
        {
            arr[rear] = -1;
            rear--;
        }

        else if (rear == 0 && front > rear)
        {
            arr[rear] = -1;
            rear = size - 1;
        }

        else
        {
            cout << "stack underflow\n";
        }
    }
};

int main()
{

    dQueue q(5);
    // q.print();
    q.push_front(-10);
    q.push_front(-20);
    q.push_front(-30);
    // q.push_front(-40);
    // q.push_front(-50);

    q.push_back(30);
    q.push_back(40);
    q.push_back(50);

    q.print();

    return 0;
}