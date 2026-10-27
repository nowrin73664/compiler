#include <iostream>
using namespace std;

void checkOperator(string s)
{
    int count = 0;
    for (int i = 0; i < s.length(); i++)

    {
        if (s[i] == '+')
        {
            cout << "Operator " << count + 1 << ": " << "+" << endl;
            count++;
        }
        else if (s[i] == '-')
        {
            cout << "Operator " << count + 1 << ": " << "-" << endl;
            count++;
        }
        else if (s[i] == '*')
        {
            cout << "Operator " << count + 1 << ": " << "*" << endl;
            count++;
        }
        else if (s[i] == '/')
        {
            cout << "Operator " << count + 1 << ": " << "/" << endl;
            count++;
        }
        else if (s[i] == '%')
        {
            cout << "Operator " << count + 1 << ": " << "%" << endl;
            count++;
        }
        else if (s[i] == '=')
        {
            cout << "Operator " << count + 1 << ": " << "=" << endl;
            count++;
        }
    }
}

int main()
{
    checkOperator("5+3-4*3/4=1");
}