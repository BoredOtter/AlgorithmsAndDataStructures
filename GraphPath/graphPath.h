#include <iostream>
#include <stack>
using namespace std;


struct weightedEdge{
    int s;
    int t;
    double w;        //waga krawędzi
};

class WeightedGraph
{
    private:
        double** adjWeightMatrix;
        int n;                //liczba węzłów
        bool directed;
    public:
        WeightedGraph(int n, int m, weightedEdge edges[], bool directed);    //tworzy graf w oparciu o pdaną listę krawędzi z wagami
        
        void printMatrix();
        void printM();

        int find(double* distance,bool* visited);
        void sp(int s,int t,int* parent);

        void Dijkstra(int s);          
        void WarshallFloyd();
        //friend ostream& operator<<(ostream& out, WeightedGraph& g);
        //~WeightedGraph();
}; 

WeightedGraph::WeightedGraph(int n, int m, weightedEdge edges[], bool directed)
{
	this->n = n;
	this->directed = directed;

	//tworze maciez z wagami
	adjWeightMatrix = new double* [this->n];

	for (int i = 0; i < n; i++)
	{
		adjWeightMatrix[i] = new double[this->n];
		for (int j = 0; j < n; j++)
		{
			if (i == j)
			{
				adjWeightMatrix[i][j] = 0;
			}
            else
            {
                adjWeightMatrix[i][j] = INT_MAX; //wypelniam wszystkie sciezki INT_MAX, na razie
            }
			
		}
	}

	//wypelniam sciezki wagami z krawedziami
	for (int i = 0; i < m; i++)
	{
		adjWeightMatrix[edges[i].s][edges[i].t] = edges[i].w;
		if (!directed) //czyli nieskierowany
		{
			adjWeightMatrix[edges[i].t][edges[i].s] = edges[i].w;
		}
	}
}

void WeightedGraph::printMatrix()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

                cout<<adjWeightMatrix[i][j]<<" ";

            
        }
        cout<<"\n";
    }
    cout<<"\n";
}

void WeightedGraph::printM()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			std::cout << adjWeightMatrix[i][j] << " ";
		}
		std::cout << "\n";
	}
}

int WeightedGraph::find(double* distance,bool* visited)
{
    int min = INT_MAX;
    int index=-1;
    for (int i = 0; i < n; i++)
    {
        if ( distance[i] < min && visited[i]==0 )
        {
            min=distance[i];
            index=i;
        }
        
    }
    return index;
    
}

void WeightedGraph::Dijkstra(int s)
{
    bool* visited       = new bool[n];
    int* parent         = new int[n];
    double* distance    = new double[n];

    //inicjowanie tego guwna wyzej
    for (int i = 0; i < n; i++)
    {
        visited[i]  =0;
        parent[i]   =-1;
        distance[i] =INT_MAX;
    }

    //dijsktra kurwa algorytm tego:
    distance[s]=0;

    for (int i = 0; i <  n; i++)
    {
        int u = find(distance,visited);
        visited[u]=1;

        for (int j = 0; j < n; j++)
        {
            //istnieje trasa
            if ( adjWeightMatrix[u][j]!=INT_MAX && j!=u)
            {
                if ( distance[j] > adjWeightMatrix[u][j] + distance[u])
                {
                    distance[j] =adjWeightMatrix[u][j] + distance[u];
                    parent[j]   =u;
                }
            }
        }
    }
    

	std::cout << "VISITED:  ";
	for (int i = 0; i < n; i++)
	{
		std::cout << visited[i] << " ";
	}
	std::cout << "\nDISTANCE: ";
	for (int i = 0; i < n; i++)
	{
		std::cout << distance[i] << " ";
	}
	std::cout << "\nPARENT:  ";
	for (int i = 0; i < n; i++)
	{
		std::cout << parent[i] << " ";
	}
	std::cout <<"\n";

    sp(s,9,parent);
    
}

void WeightedGraph::sp(int s, int t, int *parent)
{
    stack<int> sp;
    cout<<"Shortest path to node 9: ";
    sp.push(t);

    while (t!=s)
    {
        t=parent[t];
        sp.push(t);
    }

    while (!sp.empty())
    {
        cout<<sp.top()<<" ";
        sp.pop();
    }

    cout<<endl;
    
}

void WeightedGraph::WarshallFloyd()
{
	//potrzebujemy tablicy pomocniczej, do której przepisujemy wartosci macierzy wag
	double** distance = new double* [n];
	for (int i = 0; i < n; i++)
	{
		distance[i] = new double[n];
		for (int j = 0; j < n; j++)
		{
			distance[i][j] = adjWeightMatrix[i][j];
		}
	}

	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (distance[i][j] > distance[i][k] + distance[k][j])
				{
					distance[i][j] = distance[i][k] + distance[k][j];
				}
			}
		}
	}

	//TEST
	for (int i = 0; i < n; i++)
	{
		std::cout << "Najkrotsza sciezka z wezla: " << i << " do innych wezlow wynosi: ";
		for (int j = 0; j < n; j++)
		{
			if (distance[i][j]==INT_MAX)
            {
                cout<<"- ";
            }
            else
            {
                std::cout << distance[i][j] << " ";
            }
            
		}
		std::cout << std::endl;
	}
}

