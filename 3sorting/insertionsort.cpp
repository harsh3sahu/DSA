#include <iostream>
using namespace std;

void insort(int arr[], int size)
{

    for (int i = 1; i < size; i++)
    {
        // int temp = arr[i];
        int j = i - 1;
        for (; j >= 0; j--)
        {
            if (arr[j] > arr[j+1])
            {
                swap(arr[j + 1], arr[j]);
            }
            else
            {
                break;
            }
        }
        // arr[j+1] = temp;
    }

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << endl;
    }
}

int main()
{

    int arr[10] = {24, 58, 12, 56, 1, 64, 90, 10, 87, 90};
    int size = sizeof(arr) / sizeof(int);

    insort(arr, size);

    return 0;
}