#include <iostream>
#include "graphTraverse.h"

int main()
{

    int n = 8, m = 17; //m ilosc polaczen   //dwa ostanie dodane w celu testu algo na spojnosc itp
    edge directedGraph[] = { {0,4},{0,5},{1,0},{1,2},{1,4},{2,1},{2,3},{2,4},{3,2},{3,5},{4,0},{4,1},{4,3},{5,3},{5,4},{6,7},{7,6} };  //przyk³adowy graf

    Graph g(n, m, directedGraph, true);
    g.printmatrix();
    g.bfs(0);
    g.dfs(0);
    std::cout << g.isConected() << " - spojnosc" << std::endl;




    //int n = 6, m = 15; //m ilosc polaczen
    //edge directedGraph[] = { {0,4},{0,5},{1,0},{1,2},{1,4},{2,1},{2,3},{2,4},{3,2},{3,5},{4,0},{4,1},{4,3},{5,3},{5,4} };  //przyk³adowy graf

    //Graph g(n,m,directedGraph,true);
    //g.bfs(0);
    //g.dfs(0);
    //std::cout << g.isConnected() << std::endl;
    //std::cout << g.connected() << std::endl;
}

