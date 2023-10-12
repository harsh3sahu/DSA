#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int pivot, int n)
{
    int start = 0;
    int end = size - 1;
    int mid;
    int ans = -1;
    mid = (start + end) / 2;
    if (n > arr[0])
    {
        end = pivot;
        mid = (start + end) / 2;

        while (start < end)
        {

            mid = (start + end) / 2;
            if (n > arr[mid])
            {
                start = mid ;
            }

            if (n < arr[mid])
            {
                end = mid ;
            }

            else
            {
                ans = mid;
            }

            
        }
    }
    return ans;
}

int findPivot(int arr[], int size)
{
    int pivot;
    int mid;
    int start = 0;
    int end = size - 1;
    mid = (start + end) / 2;
    while (start < end)
    {

        if (arr[0] < arr[mid])
        {
            start = mid + 1;
        }
        if (arr[0] > arr[mid])
        {
            end = mid - 1;
        }
        mid = (start + end) / 2;
    }
    pivot = mid;

    return pivot;
}

int main()
{

    int arr[10] = {5, 6, 7, 8, 9, 10, 1, 2, 3, 4};
    int size = sizeof(arr) / sizeof(int);
    int n;
    cout << "enter the number\n";
    cin >> n;

    int pivot = findPivot(arr, size);

    // cout << pivot - 1 << endl;

    int ans=binarySearch(arr, size, pivot - 1, n);
    cout<<ans<<endl;

    return 0;
}