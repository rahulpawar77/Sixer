// Problem Statement: Represent flight paths as a graph and check whether the graph is connected.
#include <iostream>
#include <vector>
using namespace std;

// Depth First Search
void dfs(int v, vector<vector<int> > &adj, bool visited[])
{
    visited[v] = true;

    for (int i = 0; i < adj[v].size(); i++)
    {
        int neighbour = adj[v][i];

        if (!visited[neighbour])
            dfs(neighbour, adj, visited);
    }
}

// Main Function
int main()
{
    int n, edges;

    cout << "Enter Number of Cities: ";
    cin >> n;

    if (n <= 0)
        return 0;

    vector<vector<int> > adj(n);

    cout << "Enter Number of Flight Paths: ";
    cin >> edges;

    cout << "Enter City Connections:\n";

    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;

        if (u < 0 || u >= n || v < 0 || v >= n)
        {
            cout << "Invalid City Index!\n";
            return 0;
        }

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Display Adjacency List
    cout << "\n===== ADJACENCY LIST =====\n";

    for (int i = 0; i < n; i++)
    {
        cout << i << " -> ";

        for (int j = 0; j < adj[i].size(); j++)
            cout << adj[i][j] << " ";

        cout << endl;
    }

    // Check Connectivity
    bool *visited = new bool[n];

    for (int i = 0; i < n; i++)
        visited[i] = false;

    dfs(0, adj, visited);

    bool connected = true;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            connected = false;
    }

    if (connected)
        cout << "\nGraph is Connected\n";
    else
        cout << "\nGraph is Not Connected\n";

    delete[] visited;

    return 0;
}
