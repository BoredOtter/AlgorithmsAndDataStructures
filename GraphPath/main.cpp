#include <iostream>
#include "graphPath.h"



int main()
{

    int n = 10;
    int m = 18;
    weightedEdge w[] = {
                        {0,1,5},
                        {1,2,2},{1,7,3},
                        {2,3,7},{2,8,6},
                        {3,2,7},{3,9,5},
                        {4,0,2},
                        {5,3,2},{5,8,5},
                        {6,0,5},
                        {7,6,5},{7,1,3},{7,8,1},{7,4,1},
                        {8,7,1},{8,5,5},
                        {9,8,4}
                        };

    WeightedGraph h(n, m, w, true);
    h.printMatrix();
    h.Dijkstra(0);
	h.WarshallFloyd();

}

