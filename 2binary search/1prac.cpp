#include <iostream>
using namespace std;

int binS(int arr[], int x, int end, int start = 0)
{

    while (start <= end)
    {

        int mid = (start + end) / 2;

        if (x < arr[mid])
        {
            end = mid-1;
        }
        else if (x > arr[mid])
        {
            start = mid+1;
        }
        else
        {
            return mid;
        }
    }

    return -1;
}

int main()
{

    int arr[9] = {2, 3, 5, 7, 12, 34, 45, 123, 543};
    int x;
    cin >> x;

    int ans = binS(arr, x, 8);

    cout << ans << endl;

    return 0;
}