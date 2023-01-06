#include <bits/stdc++.h>
using namespace std;
bool isBalanced(string str)
{
    int size = str.size();
    stack<char> s;
    int i = 0;
    while (size--)
    {
        if(s.empty()) return false;
        else if (str[i] == '(' || str[i] == '{' || str[i] == '[')
        {
            s.push(str[i]); 
        }
        else if(str[i] == ')' || str[i] == '}' || str[i] == ']')
        {
            
            if (s.top() == '(' && str[i] == ')')
            {
                s.pop();
            }
            else if (s.top() == '{' && str[i] == '}')
            {
                s.pop();
            }
            else if (s.top() == '[' && str[i] == ']')
            {
                s.pop();
            }
            else
            {
                return false;
            } 
        }
        i++;
    }

    return true;
}

int main()
{
    cout << isBalanced("[]");

    return 0;
}