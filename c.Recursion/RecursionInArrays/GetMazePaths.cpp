#include<iostream>
#include<vector>

using namespace std;

// sr - source row
// sc - source column
// dr - destination row
// dc - destination column

vector <string> getMazePaths(int sr, int sc, int dr, int dc) 
{
    if (sr == dr && sc == dc)
    {
        vector<string> base;

        base.push_back("");

        return base;
    }

    vector<string> hpaths;
    vector<string> vpaths;
    vector<string> paths;
    
    if (sc < dc)
    {
        hpaths = getMazePaths(sr, sc+1, dr, dc);
    }

    if (sr < dr)
    {
        vpaths = getMazePaths(sr+1, sc, dr, dc);
    }

    for (string hpath: hpaths)
    {
        paths.push_back("h" + hpath);
    }

    for (string vpath: vpaths)
    {
        paths.push_back("v" + vpath);
    }

    return paths;

}

void display(vector<string>& arr)
{
    cout << "[";

    for(int idx = 0; idx < arr.size(); idx++)
    {
        cout << arr[idx];

        if(idx < arr.size()-1) 
        {
            cout << ", ";
        }
    }

    cout << "]"<<endl;
}

int main() 
{
    int rows, cols; 

    cin >> rows >> cols;

    vector<string> ans = getMazePaths(0,0,rows-1,cols-1);

    display(ans);

    return 0;

}