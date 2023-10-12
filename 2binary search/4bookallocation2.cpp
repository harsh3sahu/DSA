#include <iostream>
using namespace std;

bool pos(int p[], int stu, int size, int mid)
{
    int sum = 0;
    int studentcount = 1;

    for (int i = 0; i < size; i++)
    {
        if (mid >= sum + p[i])
        {
            sum = sum + p[i];
        }
        else
        {
            studentcount++;
            if (studentcount > stu || p[i] > mid)
            {
                return false;
            }
            sum = p[i];
        }
        
    }

    return true;
}

int book(int p[], int stu, int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum = sum + p[i];
    }

    int start = 0;
    int end = sum;
    int mid = (start + end) / 2;
    int ans = -1;

    while (start <=end)
    {
        if (pos(p, stu, size, mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
        mid = (start + end) / 2;
    }
    return ans;
}

int main()
{

    int pages[4] = {12, 34, 67, 90};
    int students = 2;

    int size = sizeof(pages) / sizeof(int);

    int ans = book(pages, students, size);

    cout << ans;

    return 0;
}