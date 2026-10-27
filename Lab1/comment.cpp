#include <iostream>
using namespace std;

void checkCmt(string s)
{

    int indexB = 0;
    for (int i = 0; i < s.length() - 1; i++)

    {
        if (s[i] == '/' && s[i + 1] == '/')
        {
            indexB = i;
            cout << "singleline comments" << endl;
        }
        if ((s[i] == '/') && (s[i + 1] == '*'))
        {
            for (int j = i + 2; j < s.length(); j++)
            {
                if (s[j] == '/' && s[j - 1] == '*')
                {
                    cout << " multiline comments " << endl;
                    return;
                }
            }
            cout << " multiline comments " << endl;
            return;
        }
    }
}

int main()
{
    checkCmt("int x = 5 // taking input");
    checkCmt("int x; /*here*/");
    checkCmt("int x; /*we got it*/");
}