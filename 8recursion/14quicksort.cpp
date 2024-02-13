#include <iostream>
using namespace std;

int partition(int arr[], int start, int end)
{
    int pivot=arr[start];
    int count = 0;
    for (int i = start + 1; i <= end; i++ )
    {
        if (arr[i] <= pivot)
        {
            count++;
        }
    }
    int pivotindex = start + count ;
    swap(arr[pivotindex], arr[start]);
    int i = start;
    int j = end;
    // cout << "okay check 2" << endl;

    while (i < pivotindex && j > pivotindex)
    {

        // cout << "okay check 3" << endl;

        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }

        if (i < pivotindex && j > pivotindex)
        {
            swap(arr[i++], arr[j--]);
            
        }
    }
    // cout << "okay check 4" << endl;

    return pivotindex;
}

void qSort(int arr[], int start, int end)
{
    // int pivot = arr[start];

    if (start >= end)
    {
        return;
    }
    // cout << "okay check 1" << endl;
    int pos = partition(arr, start, end);

    qSort(arr, start, pos - 1);
    qSort(arr, pos + 1, end);
}

int main()
{

    int arr[10] = {12, 100, 32, 11, 34, 54, 23, 4, 67, 2};
    int size = sizeof(arr) / sizeof(int);

    qSort(arr, 0, size - 1);

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}