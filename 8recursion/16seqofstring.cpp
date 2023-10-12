#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve(string str, string output, vector<string>& ans, int index)
{

    if (index >= str.size())
    {
        ans.push_back(output);
        return;
    }

    solve(str, output, ans, index + 1);

    char element = str[index];
    output.push_back(element);
    solve(str, output, ans, index + 1);
}

int main()
{

    string str = "abc";

    vector<string> ans;
    string output;
    int index = 0;

    solve(str, output, ans, index);

    for (const auto& row : ans) {
        // Iterate over the columns of the vector
        for (const auto& col : row) {
            // Print the current element
            cout << col << ' ';
        }
        // Print a newline character after each row
        cout << '\n';
    }
   
    return 0;
}
