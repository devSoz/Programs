#include <iostream>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include <queue>

using namespace std;

struct Node
{
    int dest;
    struct Node *next;
    bool visited;
};

struct AdjList
{
    struct Node *head;
};

struct Graph
{
    int vertices;
    struct AdjList *list;
};

struct Node *createNode(int dest)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

struct Graph *createGraph(int nVertices)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->vertices = nVertices;

    graph->list = (struct AdjList *)malloc(nVertices * sizeof(struct AdjList));

    for (int i = 0; i < nVertices; ++i)
        graph->list[i].head = NULL;

    return graph;
}

void addEdge(struct Graph *graph, int src, int dest)
{
    struct Node *newNode = createNode(dest);
    newNode->next = graph->list[src].head;
    graph->list[src].head = newNode;

    newNode = createNode(src);
    newNode->next = graph->list[dest].head;
    graph->list[dest].head = newNode;
}

void printGraph(struct Graph *graph)
{
    int v;
    for (v = 0; v < graph->vertices; ++v)
    {
        struct Node *temp = graph->list[v].head;
        printf("\n Adjacency list of vertex %d\n head ", v);
        while (temp)
        {
            printf("-> %d", temp->dest);
            temp = temp->next;
        }
        printf("\n");
    }
}

bool isComplete(struct Graph *graph, int nEdges)
{
    int checkSum = (graph->vertices) * (graph->vertices - 1) / 2;
    for (int i = 0; i < graph->vertices; i++)
    {
        int sum = 0;
        struct Node *temp = graph->list[i].head;
        while (temp)
        {
            sum++;
            temp = temp->next;
        }
        if (sum != nEdges - 1)
            return false;
    }
    return true;
}

int getDegree(struct Graph *graph, int vertex)
{
    int isVisited = 0, x;
    for (int i = 0; i < graph->vertices; i++)
    {
        int sum = 0;
        struct Node *temp = graph->list[i].head;
        if (i == vertex)
        {
            isVisited = 1;
            x = 0;
            while (temp)
            {
                x++;
                temp = temp->next;
            }
        }
        if (isVisited)
            return x;
    }
    return -1;
}

int main()
{
    int nEdges, nVertices, src, dest;

    cout << "Enter number of vertices: ";
    cin >> nVertices;
    struct Graph *graph = createGraph(nVertices + 1);

    cout << "Enter number of edges: ";
    cin >> nEdges;

    cout << "Enter the terminal vertices of edges in the graph and their costs: \n";
    for (int i = 0; i < nEdges; i++)
    {
        cin >> src >> dest;
        addEdge(graph, src, dest);
    }
    if (isComplete(graph, nEdges))
        cout << "The graph is complete";
    else
        cout << "The graph is not complete";
    cout << "\nEnter the vertex to find the degree: ";
    cin >> src;
    cout << "Degree of vertex " << src << ": " << getDegree(graph, src);
    //printGraph(graph);
    return 0;
}

/*
int main()
{
    // Create a graph given in the above diagram
    int nEdges, nVertices, start, end, cost, source, dest, choice;
    //n-Number of edges, start & end-terminal vertices, cost-cost

  //  cout << "Enter number of vertices: ";
    cin >> nVertices;
    Graph graph(nVertices+1);

  //  cout << "Enter number of edges: ";
    cin >> nEdges;

   // cout << "Enter the terminal vertices of edges in the graph and their costs: \n";
    for (int i = 0; i < nEdges; i++)
    {
        cin >> start >> end >> cost;
        graph.addEdge(start, end, cost);
    }

    do
    {
       // cout << "\n\nEnter source and destination: ";
        cin >> source >> dest;
        //To keep track of whether the vertices are visited or not
        bool *isVisited = new bool[graph.getVertices()];

        // To store the current path
        int *route = new int[graph.getVertices()];
        int index = 0; // Initialize route[] as empty

        // Mark all the vertices as false (not visited) initially
        memset(isVisited, false, sizeof(isVisited));
        cout << "All possible paths between " << source << " & " << dest << ": \n";
        graph.getAllPaths(source, dest, isVisited, route, index);
       // cout << "\n\nDo you wish to continue? (press -1 to stop): ";
        cin >> choice;
    } while (choice != -1);

    return 0;
}*/
