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
        vector <string> base;

        base.push_back("");

        return base;
    }

    vector<string> paths;

    for (int horizontal = 1; horizontal <= dc - sc; horizontal++)
    {
        vector <string> hpaths = getMazePaths(sr, sc+horizontal, dr, dc);

        for (string hpath: hpaths)
        {
            paths.push_back("h" + to_string(horizontal) + hpath);
        }
    }
    
    for (int vertical = 1; vertical <= dr - sr; vertical++)
    {
        vector <string> vpaths = getMazePaths(sr+vertical, sc, dr, dc);

        for (string vpath: vpaths)
        {
            paths.push_back("v" + to_string(vertical) + vpath);
        }
    }
    
    for (int diagonal = 1; diagonal <= dc - sc && diagonal <= dr - sr; diagonal++)
    {
        vector <string> dpaths = getMazePaths(sr+diagonal, sc+diagonal, dr, dc);

        for (string dpath: dpaths)
        {
            paths.push_back("d" + to_string(diagonal) + dpath);
        }
    }

    return paths;
}

void display(vector<string>& arr)
{
    cout << "[";

    for(int idx = 0; idx < arr.size(); idx++)
    {
        cout << arr[idx];

        if(idx < arr.size() -1) 
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

    vector<string> ans = getMazePaths(1,1,rows,cols);

    display(ans);

    return 0;

}