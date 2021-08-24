#include <iostream>
using namespace std;

static string codes[] = {".;", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz"};

void printKPC(string ques, string asf)
{
    if (ques.size() == 0)
    {
        cout << asf << endl;

        return;
    }

    int index = ques[0] -'0';

    string ros = ques.substr(1);

    string toAdd = codes[index];
    
    for (int idx = 0; idx < toAdd.size(); idx++)
    {
        printKPC (ros, asf + toAdd[idx]);
    }
}

int main()
{
    string str;

    cin >> str;

    printKPC(str, "");

    return 0;

}