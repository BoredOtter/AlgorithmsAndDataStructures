#include <iostream>
#include <ostream>
#include <queue>
using namespace std;
struct edge
{
    int s;
    int t;
};

class Graph {
private:
    int** adjMatrix;
    int n;                              //liczba węzłów
    bool directed;              //true - graf skierowany, false - graf nieskierowany
    void dfs(int s, bool* visited);    //wykonuje przeszukiwanie i wyświetla węzły w porządku odwiedzenia
public:
    Graph(int n, int m, edge edges[], bool directed);    //tworzy graf w oparciu o pdaną listę krawędzi
    void bfs(int s);                //wykonuje przeszukiwanie i wyświetla węzły w porządku odwiedzenia
    void dfs(int s);                //metoda pomocnicza dla dfs - tworzy tabelę visited i wywołuję metodę prywatną dfs
    bool isConected();

    void printmatrix();

    int connected();


    //friend ostream& operator<<(ostream& out, Graph& g);  //wyświetla graf
    //~Graph();
};

Graph::Graph(int n, int m, edge edges[], bool directed)
{
    this->n = n;
    this->directed = directed;

    adjMatrix = new int* [n];

    for (int i = 0; i < n; i++)
    {
        adjMatrix[i] = new int[n] {0};
    }

    for (int i = 0; i < m; i++)
    {
        adjMatrix[edges[i].s][edges[i].t] = 1;
    }

    if (!directed)
    {
        for (int i = 0; i < m; i++)
        {
            adjMatrix[edges[i].t][edges[i].s] = 1;
        }
    }

}

void Graph::printmatrix()
{
    for (size_t i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << adjMatrix[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

void Graph::bfs(int s)
{
    cout << "BFS: ";
    bool* visited = new bool[n] {0};
    visited[s] = 1;
    queue<int> q;
    q.push(s);

    while (!q.empty())
    {
        for (int i = 0; i < n; i++)
        {
            if (adjMatrix[q.front()][i] == 1 && visited[i] == 0)
            {
                q.push(i);
                visited[i] = 1;
            }

        }

        cout << q.front() << " ";
        q.pop();

    }
    cout << "\n";

}

void Graph::dfs(int s)
{
    bool* visited = new bool[n] {0};
    std::cout << "DFS: ";
    dfs(s, visited);
    delete[] visited;
    std::cout << "\n";
}

void Graph::dfs(int s, bool* visited)
{
    cout << s << " ";
    visited[s] = 1;

    for (int i = 0; i < n; i++)
    {
        if (adjMatrix[s][i] == 1 && visited[i] == 0)
        {
            dfs(i, visited);
        }
    }

}

bool Graph::isConected()
{
    bool* visited = new bool[n] {0};
    int parts = 0;

    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            cout << "skladowa " << parts << "\n";
            parts++;
            dfs(i, visited);
            cout << "\n";
        }

    }

    if (parts == 1)
    {
        return true;
    }
    return false;


}