#include <iostream>
#include <vector>
#include <queue>
#include <omp.h>

using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int v, int w) {
        adj[v].push_back(w);
    }

    // -------- DFS ----------
    void DFS(int start) {
        vector<bool> visited(V, false);
        cout << "Parallel DFS: ";
        DFSUtil(start, visited);
        cout << endl;
    }

    void DFSUtil(int v, vector<bool> &visited) {
        bool alreadyVisited = false;

        #pragma omp critical
        {
            if (visited[v])
                alreadyVisited = true;
            else {
                visited[v] = true;
                cout << v << " ";
            }
        }

        if (alreadyVisited) return;

        #pragma omp parallel for
        for (int i = 0; i < adj[v].size(); i++) {
            int n = adj[v][i];
            DFSUtil(n, visited);
        }
    }

    // -------- BFS ----------
    void BFS(int start) {
        vector<bool> visited(V, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "Parallel BFS: ";

        while (!q.empty()) {
            int v = q.front();
            q.pop();

            cout << v << " ";

            #pragma omp parallel for
            for (int i = 0; i < adj[v].size(); i++) {
                int n = adj[v][i];

                #pragma omp critical
                {
                    if (!visited[n]) {
                        visited[n] = true;
                        q.push(n);
                    }
                }
            }
        }

        cout << endl;
    }
};

int main() {
    Graph g(7);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.addEdge(2, 6);

    g.DFS(0);
    g.BFS(0);

    return 0;
}
