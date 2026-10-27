#include <iostream>
using namespace std;
void check(string s)
{
    bool flag = true;
    int count = 0;

    for (int i = 0; i < s.length(); i++)
    {

        if ((int)s[i] > 47 && (int)s[i] < 58)
        {
        }
        else if ((int)s[i] == 46)
        {
            count++;
            if (count > 1)
            {
                flag = false;
                break;
            }
        }
        else
        {
            flag = false;
            break;
        }
    }
    if (flag)
    {
        cout << s << " is Numerical" << endl;
    }
    else
    {
        cout << s << " is not Numerical" << endl;
    }
}
int main()
{
    check("100");
    check("10BD0");
    check("11.00.");
    check("1010");
}