#include <iostream>
using namespace std;

int sqr(int N)
{

    int s = 0;
    int e = N - 1;
    int mid = (s + e) / 2;
    long long int sq;
    long long int ans = -1;
    while (s <= e)
    {
        sq = mid * mid;
        if (sq == N)
        {
            ans = mid;
        }

        if (sq < N)
        {
            ans = mid;
            s = mid + 1;
        }

        else
        {

            e = mid - 1;
        }
        mid = (s + e) / 2;
    }
    return ans;
}

double pRoot(int n, int p, int r)
{

    double factor = 1;
    double ans = r;
    for (int i = 0; i < p; i++)
    {
        factor = factor / 10;

        for (double j = ans; j*j< n; j = j + factor)
        {
            ans = j;
        }
    }
    return ans;
}

int main()
{

    int N;
    cout << "enter a number\n";
    cin >> N;

    int root = sqr(N);
    double ans= pRoot(N, 3, root);

    cout << ans;
    return 0;
}