#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;
    void goToAllPathsUtil(int v1, int v2, bool visited[], int path[], int index);

public:
    Graph(int V);

    bool pathExist;

    void addEdge(int v, int w);

    void goToAllPaths(int v1, int v2);

    bool isCyclicUtil(int v, bool visited[], bool *rs); // used by isCyclic()
    void printDegree(int v, int nVertices);
    void BFS(int s);
    void DFS(int v, bool *visited);
    void finishingTimeDFS(int v, bool *visited, int *FT);
    bool isCyclic();
    void printPathBFS(int s, int d);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

void Graph::goToAllPathsUtil(int v1, int v2, bool visited[], int path[], int index)
{
    visited[v1] = true;
    path[index] = v1;
    index++;

    if (v1 == v2)
    {
        pathExist = true;
    }
    else
    {
        list<int>::iterator i;
        for (i = adj[v1].begin(); i != adj[v1].end(); ++i)
            if (!visited[*i])
                goToAllPathsUtil(*i, v2, visited, path, index);
    }

    index--;
    visited[v1] = false;
}

void Graph::goToAllPaths(int v1, int v2)
{
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    int *path = new int[V];

    int index = 0;

    pathExist = false;

    goToAllPathsUtil(v1, v2, visited, path, index);
}

void Graph::printDegree(int v, int nVertices)
{
    int inC = 0, outC = 0;

    list<int>::iterator it;
    for (it = adj[v].begin(); it != adj[v].end(); ++it)
        outC++;

    for (int i = 0; i < nVertices; i++)
    {
        list<int>::iterator t;
        for (t = adj[i].begin(); t != adj[i].end(); ++t)
        {
            if (*t == v)
                inC++;
        }
    }

    if (inC == outC)
        cout << "Degree of vertex " << v << " is: " << inC << endl;
    else
        cout << "\nIndegree=" << inC << " and "
             << "Outdegree=" << outC << " for vertex " << v << endl;
}

void Graph::BFS(int s)
{

    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    list<int> queue;

    visited[s] = true;
    queue.push_back(s);

    list<int>::iterator i;

    while (!queue.empty())
    {

        s = queue.front();
        cout << s << " ";
        queue.pop_front();

        for (i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }

    cout << endl;
}

void Graph::printPathBFS(int s, int d)
{

    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    list<int> queue;
    unordered_map<int, int> m;

    visited[s] = true;
    queue.push_back(s);

    list<int>::iterator i;

    while (!queue.empty() && queue.front() != d)
    {

        int currV = queue.front();
        queue.pop_front();

        for (i = adj[currV].begin(); i != adj[currV].end(); ++i)
        {
            if (!visited[*i])
            {
                m[*i] = currV;
                visited[*i] = true;
                queue.push_back(*i);
            }

            if (*i == d)
                break;
        }
    }

    if (queue.size() == 0)
        return;
    else
    {
        vector<int> *r = new vector<int>();
        r->push_back(d);
        for (int i = d; i != s; i = m[i])
            r->push_back(m[i]);

        for (int i = r->size() - 1; i >= 0; i--)
            cout << r->at(i) << " ";
    }

    cout << endl;
}

void Graph::DFS(int v, bool *visited)
{
    visited[v] = true; 
    cout << v << " ";

    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFS(*i, visited);
}

int x = 1;

void Graph::finishingTimeDFS(int v, bool *visited, int *FT)
{
    FT[v] = x;
    x++;
    visited[v] = true;

    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            finishingTimeDFS(*i, visited, FT);
}

bool Graph::isCyclicUtil(int v, bool visited[], bool *recStack)
{
    if (visited[v] == false) 
    {
        visited[v] = true;
        recStack[v] = true;

        list<int>::iterator i;
        for (i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            if (!visited[*i] && isCyclicUtil(*i, visited, recStack))
                return true;
            else if (recStack[*i])
                return true;
        }
    }
    recStack[v] = false; 
    return false;
}

bool Graph::isCyclic() 
{
    bool *visited = new bool[V]; 
    bool *recStack = new bool[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
        recStack[i] = false;
    }

    for (int i = 0; i < V; i++) 
        if (isCyclicUtil(i, visited, recStack))
            return true;

    return false;
}

int main()
{
    int nVertices = 0, nE;
    cin >> nE;

    Graph g(nE);
    cout << "Enter edges: \n";
    for (int i = 0; i < nE; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        g.addEdge(v1, v2);

        nVertices = max(nVertices, v1);
        nVertices = max(nVertices, v2);
    }
    nVertices++;

    cout << "Enter vertex to find degree: ";
    int v;
    cin >> v;

    cout << "Enter vertices(ending, starting) to check path: ";
    int v1, v2;
    cin >> v1 >> v2;

    g.goToAllPaths(v1, v2);

    cout << "\n\nIs input graph a complete graph: ";
    if ((nE * (nE - 1)) / 2 == nVertices)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    g.printDegree(v, nVertices);
    cout << "\nBFS: ";
    g.BFS(0);

    bool visited[nVertices] = {0}; 
    cout << "\nDFS: ";      
    g.DFS(0, visited);
    cout << "\nDoes path exist between " << v1 << " and " << v2 << ": ";
    if (g.pathExist)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    bool visitedV[nVertices] = {0}; 
    int finish[nVertices];
    cout << "\nFinishing time: " << endl;
    g.finishingTimeDFS(0, visitedV, finish);
    for (int i = 0; i < nVertices; i++)
        cout << i << ":\t" << finish[i] << endl;
}
