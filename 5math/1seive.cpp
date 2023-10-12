#include <iostream>
#include <vector>
using namespace std;

int countPrime(int n)
{
    vector<bool> prime(n + 1, true);

    prime[0] = prime[1] = false;
    int count = 0;
    for (int i = 2; i < n; i++)
    {
        if (prime[i])
        {
            count++;

            for (int j = 2; j * i < n; j++)
            {
                prime[j * i] = false;
            }
        }
    }
    return count;
}

int main()
{

    int n;
    cout << "enter the digit \n";
    cin >> n;

    int ans = countPrime(n);

    cout << ans;

    return 0;
}