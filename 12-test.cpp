#include <bits/stdc++.h>
using namespace std;

bool dfsDetectCycle(int **edges, int n, int vertex, int visited[10])
{
    stack<int> s;

    s.push(vertex);

    while (!s.empty())
    {
        int np_vertex = s.top();
        s.pop();
        if (visited[np_vertex])
        {
            return true;
        }
        visited[np_vertex] = 1;
        for (int j = 0; j < n; ++j)
            if (edges[np_vertex][j] && !visited[j])
            {
                s.push(j);
            }
    }

    return false;
}

bool isCyclic(int **edges, int n)
{

    int visited[10] = {0};
    for (int i = 0; i < n; ++i)
    {
        if (!visited[i])
        {
            if (dfsDetectCycle(edges, n, i, visited))
                return true;
        }
    }
    return false;
}

void DFT(int **edges, vector<bool> &visited, int n, int start = 0)
{
    cout << start << " ";
    visited[start] = true;

    for (int i = 0; i < n; i++)
    {
        if (edges[start][i] == 1 && (!visited[i]))
        {
            DFT(edges, visited, n, i);
        }
    }
}

void bfs(int **edges, int N)
{
    vector<bool> visited(N, false);
    vector<int> distance(N, 0);
    vector<int> prev(N, -1);
    queue<int> q;
    q.push(0);
    visited[0] = true;
    distance[0] = 0;
    prev[0] = -1;
    vector<int> path;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        path.push_back(u);
        for (int v = 0; v < N; v++)
        {
            if (!visited[v] && (edges[u][v] == 1))
            {
                q.push(v);
                visited[v] = true;
                distance[v] = distance[u] + 1;
                prev[v] = u;
            }
        }
    }

    cout << "Breadth First Traversal: ";
    for (auto d : path)
        cout << d << " ";
    cout << endl;

    vector<int> route;
    int find = 7;
    route.push_back(find);
    while (prev[find] != -1)
    {
        route.push_back(prev[find]);
        find = prev[find];
    }
    cout << "\nShortest path : ";
    for (int i = route.size() - 1; i >= 0; i--)
        cout << route[i] << " ";
}

int main()
{

    int n;
    int e;
    cin >> n >> e;
    vector<bool> visited(n, false);
    int **edges = new int *[n];

    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
            edges[i][j] = 0;
    }

    for (int i = 0; i < e; i++)
    {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    cout << "\nDepth First Traversal : ";

    DFT(edges, visited, n);
    cout << "\n";
    vector<bool> found(n);

    if (isCyclic(edges, n))
    {
        cout << "The graph contains a cycle";
    }
    else
    {
        cout << "The graph doesn't contain any cycle";
    }
}