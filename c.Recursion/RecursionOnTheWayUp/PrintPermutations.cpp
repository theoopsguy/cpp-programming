#include <iostream>
#include <string>
using namespace std;

void printPermutations(string str, string asf)
{
    if (str.size()==0)
    {
        cout<<asf<<endl;

        return;
    }

    for (int idx = 0; idx < str.size(); idx++)
    {
        char ch = str[idx];

        string ros = str;

        ros.erase(ros.begin() + idx);
        
        printPermutations(ros, asf + ch);
    }
}

int main()
{
    string str;

    cin>>str;

    printPermutations(str, "");

    return 0;
    
}