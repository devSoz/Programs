#include <bits/stdc++.h>
using namespace std;

int **storeInputGraph(int nV, int nE)
{
    int **arr = new int *[nV];
    for (int i = 0; i < nV; i++)
    {
        arr[i] = new int[nV];
        for (int j = 0; j < nV; j++)
            arr[i][j] = 0;
    }
    for (int i = 0; i < nE; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        arr[v1][v2] = 1;
        arr[v2][v1] = 1;
    }
    return arr;
}

void checkCompleteGraph(int **arr, int nV, int nE)
{
    //No self loops+number of edges
    cout << "\n\nIs given input graph a Complete graph: ";
    for (int i = 0; i < nV; i++)
    {
        if (arr[i][i] > 0)
        {
            cout << "No" << endl;
            return;
        }
    }
    if ((nE * (nE - 1)) / 2 == nV)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

int main()
{
    int nV, nE;
    cin >> nV >> nE;
    int **arr = storeInputGraph(nV, nE); // storing input graph in Adjacency
    Matrix int currV;
    cout << "Enter vertex to find degree: ";
    cin >> currV;
    int v1, v2;
    cout << "Enter vertices v1 & v2 to check path : ";
    cin >> v1 >> v2;
    checkCompleteGraph(arr, nV, nE);
    findDegreeOfVertex(arr, nV, currV);
    hasPathV1toV2(arr, nV, v1, v2);
}