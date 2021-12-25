#include <iostream>
#include <queue>
using namespace std;

void printBFS (int **edges, int n, int sv) {
    bool* visited = new bool[n];
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }
    
    queue<int> pendingVertices;

    pendingVertices.push(sv);
    visited[sv] = true;

    while (!pendingVertices.empty()) {
        int currentVertex = pendingVertices.front();
        pendingVertices.pop();
        cout<<currentVertex<<endl;
        for (int i = 0; i < n; i++) {
            if (i == currentVertex) {
                continue;
            }
            if (edges[currentVertex][i] && !visited[i]) {
                pendingVertices.push(i);
                visited[i] = true;
            }
        }
    }

    delete[] visited;
}

int main() {
    int n;
    int e;
    cin>>n>>e;
    int **edges = new int*[n];
    for (int i = 0; i < n; i++) {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++) {
            edges[i][j] = 0;
        }
    }

    for (int i = 0; i < e; i++) {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    printBFS(edges, n, 0);
}