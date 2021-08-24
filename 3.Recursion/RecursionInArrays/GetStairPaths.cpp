#include<bits/stdc++.h>
using namespace std;

vector<string> stairPaths(int number)
{
    if (number == 0)
    {
        vector<string> base;

        base.push_back("");

        return base;
    }

    else if (number < 0)
    {
        vector<string> base;

        return base;
    }

    vector<string> paths1 = stairPaths(number - 1);
    vector<string> paths2 = stairPaths(number - 2);
    vector<string> paths3 = stairPaths(number - 3);

    vector<string> paths;
    
    for (string path: paths1)
    {
        paths.push_back("1" + path);
    }

    for (string path: paths2)
    {
        paths.push_back("2" + path);
    }

    for (string path: paths3)
    {
        paths.push_back("3" + path);
    }
    
    return paths;

}

void print(vector<string>& ans)
{
    cout << '[';
    
    for(int idx = 0; idx < ans.size(); idx++)
    {
        if(idx != ans.size() - 1)
        {
          cout << ans[idx] << ", ";
        }

        else
        {
            cout << ans[idx];
        } 
    }
    
    cout << "]";
}

int main()
{
    int noofStairs;
    
    cin >> noofStairs;
    
    vector<string> ans = stairPaths(noofStairs);
    
    print(ans);
    
    return 0;
}