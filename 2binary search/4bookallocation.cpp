#include <iostream>
using namespace std;

bool pos(int arr[], int size, int m, int mid)
{
    int sum =0;
    int studentcount = 1;
    for (int i = 0; i < size; i++)
    {
        if (mid >= sum + arr[i])
        {
            sum = sum + arr[i];
        }
        else
        {
            studentcount++;
            if (studentcount > m || mid < arr[i])
            {
                return false;
            }
            sum = arr[i];
        }
    }
    return true;
}

int book(int arr[], int size, int m)
{

    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum = sum + arr[i];
    }

    int s = 0;
    int e = sum;
    int mid = (s + e) / 2;
    int ans = -1;

    while (s <= e)
    {
        if (pos(arr, size, m, mid))
        {
            ans = mid;
            e = mid - 1;
        }

        else
        {
            s = mid + 1;
        }

        
        mid = (s + e) / 2;
    }

    return ans;
}

int main()
{

    int arr[4] = {12, 34, 67, 90};
    int students = 2;

    int size = sizeof(arr) / sizeof(int);

    int ans = book(arr, size, students);

    cout << ans;

    return 0;
}