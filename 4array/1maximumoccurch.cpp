#include <iostream>
using namespace std;

char count(string str)
{

    int c[26] = {0};
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        int num = 0;
        if (ch >= 'a' && ch <= 'z')
        {
            num = ch - 'a';
            c[num]++;
        }
        else
        {
            num = ch - 'A';
            c[num]++;
        }
    }
    int ans=0;
    int max=0;
    for(int i=0; i<26; i++){
        
        if(max<c[i]){
            ans=i;
            max=c[i];
        }
    }
    return ans+'a';
}

int main()
{

    string s;
    cin >> s;

    cout<<count (s);


    return 0;
}