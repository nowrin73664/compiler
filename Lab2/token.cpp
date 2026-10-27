#include <iostream>
#include <fstream>
using namespace std;
string search(string arr[], int size, string token, string arrName)
{

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == token)
        {
            return arrName;
        }
    }
    return "Unknown";
}
void tokens(string symbol)
{
    string token = symbol;
    string keywords[] = {"int", "float", "return", "char", "void", "cout"};
    string identifiers[] = {"main", "x", "y"};
    string operators[] = {"+","*","=", "-", "/", "<<", "/"};
    string puntuations[] = {"(", ")", "{", "}", ";"};
    string constant[] = {"0", "10"};

    int keywordsSize = sizeof(keywords) / sizeof(keywords[0]);
    int identifiersSize = sizeof(identifiers) / sizeof(identifiers[0]);
    int operatorsSize = sizeof(operators) / sizeof(operators[0]);
    int puntuationsSize = sizeof(puntuations) / sizeof(puntuations[0]);
    int constantSize = sizeof(constant) / sizeof(constant[0]);

    string result = search(keywords, keywordsSize, token, "keywords");

    if (result == "Unknown")
    {
        result = search(identifiers, identifiersSize, token, "identifiers");
    }
    if (result == "Unknown")
    {
        result = search(operators, operatorsSize, token, "operators");
    }
    if (result == "Unknown")
    {
        result = search(puntuations, puntuationsSize, token, "puntuations");
    }
    if (result == "Unknown")
    {
        result = search(constant, constantSize, token, "constant");
    }
    if (result == "Unknown")
    {
        result = "invalid token";
    }

    cout << token << " : " << result << endl;
}
void show(int first, int last, string c)
{
    string token = "";
    for (int j = first; j < last; j++)
    {
        // cout << c[j];
        token= token+c[j];
    }
    tokens(token);
}
void checkToken(string c)
{
    string token = "";
    int firstpositon = 0;
    int lastpositon = c.length();
    for (int i = firstpositon; i < lastpositon; i++)
    {
        if (c[i] == ' ')
        {
            lastpositon = i;
            show(firstpositon, lastpositon, c);
            firstpositon = lastpositon + 1;
            lastpositon = c.length();
        }
    }
}
int main()
{
    string c;

    ifstream txt("../symbol.txt");

    while (getline(txt, c))
    {
        checkToken(c);
    }
    txt.close();
}