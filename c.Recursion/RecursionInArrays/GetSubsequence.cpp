#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> gss (string str)
{
    if (str.size() == 0)
    {
        vector<string> empty;

        empty.push_back("");

        return empty;
    }
    
    char ch = str[0];
    
    vector <string> ros = gss (str.substr(1));

    vector <string> ans;

    for (int idx = 0; idx < ros.size(); idx++)
    {
        ans.push_back("" + ros[idx]);
    }

    for (int idx = 0; idx < ros.size(); idx++)
    {
        ans.push_back(ch + ros[idx]);
    }

    return ans;

}

int main()
{
    string str;

    cin >> str;

    vector<string> ans = gss(str);

    int cnt = 0;

    cout << '[';

    for (string str : ans)
    {
        if (cnt != ans.size() - 1)
        {
            cout << str << ", ";
        }

        else
        {
            cout << str;
        }

        cnt++;
    }

    cout << ']';

    return 0;

}