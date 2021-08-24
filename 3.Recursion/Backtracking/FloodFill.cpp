#include<iostream>
#include<vector>

using namespace std;

// sr = source row
// sc = source col

void floodfill(vector<vector<int>>& maze, int sr, int sc, string asf) 
{
    if (sr == maze.size()-1 && sc == maze[0].size()-1)
    {
        cout<<asf<<endl;

        return;
    }
    
    if (sr-1 >= 0 && maze[sr-1][sc] != 1)
    {
        maze[sr][sc] = 1;

        floodfill(maze, sr-1, sc, asf + "t");

        maze[sr][sc] = 0;
    }
    
    if (sc-1 >=0 && maze[sr][sc-1] != 1)
    {
        maze[sr][sc] = 1;

        floodfill(maze, sr, sc-1, asf + "l");

        maze[sr][sc] = 0;
    }
    
    if (sr+1 <= maze.size()-1 && maze[sr+1][sc] != 1)
    {
        maze[sr][sc] = 1;

        floodfill(maze, sr+1, sc, asf + "d");

        maze[sr][sc] = 0;
    }
    
    if (sc+1 <= maze[0].size()-1 && maze[sr][sc+1] != 1)
    {
        maze[sr][sc] = 1;

        floodfill(maze, sr, sc+1, asf + "r");

        maze[sr][sc] = 0;
    }
}

int main() 
{
    int rows, cols;

    cin >> rows >> cols;

    vector < vector <int>> arr(rows, vector <int> (cols));

    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            cin >> arr[row][col];
        }        
    }

    floodfill(arr, 0, 0, "");

    return 0;

}