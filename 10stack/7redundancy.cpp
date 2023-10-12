#include <iostream>
#include <stack>

using namespace std;

bool checkRed( string &str)
{
    stack<char>s;
    for (int i = 0; i < str.size(); i++)
    {

        char ch = str[i];

        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            s.push(ch);
        }

        else
        {
            if (ch == ')')
            {
                bool red = true;
                
                while (s.top() != '(')
                {
                    char top = s.top();
                    if (top == '+' || top == '-' || top == '*' || top == '/')
                    {
                        red = false;
                    }
                    s.pop();
                                        cout<<"\n check point\n";

                }

                if (red == true)
                {

                    return true;
                }
                s.pop();
            }

        }
    }

    return false;
}

int main()
{

    string str;
    cout << "enter the expression\n";
    cin>>str;
    
    bool a;
    a = checkRed(str);

    if(a==1)
    {
        cout << "there is redundancy\n";
    }

    else
    {
        cout << "there is NO redundancy\n";
    }

    return 0;
}





