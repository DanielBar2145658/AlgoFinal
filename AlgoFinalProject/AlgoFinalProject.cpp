#include <limits.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>


//using namespace std; <- distance is ambiguous -_-

#define EMPTY -9999999
#define VerticeAmt 23 //<- Vertice amount this
std::vector<int> path;
//const int vert = 90 <- also screamed at me unfourt
//int Vert;
//int cost[10][10]; <- visual studio screamed at me about wasting bytes
//int source;




//find the index with the minimum value
int minimumDistance(int distance[], bool visitTree[])
{

    //int minimum = INFINITY is 0 :(
    int minIndex = 0;
    int minimum = 99999;
    for (int i = 0; i < VerticeAmt; i++)
    {
        
        if (distance[i] <= minimum && visitTree[i] == false)
        {
            minimum = distance[i];
            minIndex = i;
            
         

            //std::cout << minimum;
            //std::cout <<visitTree[i]; <- dumb 
        }
    }
    return minIndex; // returns the index with the minimum value

}



void dijkstraAlg(int Giraffe[VerticeAmt][VerticeAmt], int sourceIndex)
{
    bool shortestPath[VerticeAmt];
    int distance[VerticeAmt];
    
//  distance[sourceIndex] = 0; <- order of execution screws this up and makes everything the integer limit
    for (int i = 0; i < VerticeAmt; i++)
    {
        distance[i] = 99999;
        shortestPath[i] = false;
    }
    distance[sourceIndex] = 0;
    for (int i = 0; i <= VerticeAmt - 1; i++)
    {
        int VertexPick = minimumDistance(distance, shortestPath);
        shortestPath[VertexPick] = true;
        

        
        for (int j = 0; j < VerticeAmt; j++)
        {
            if (Giraffe[VertexPick][j] && !shortestPath[j] &&
                distance[VertexPick] != 99999
                && distance[VertexPick] + Giraffe[VertexPick][j] <= distance[j])
            {
                distance[j] = distance[VertexPick] + Giraffe[VertexPick][j];
                
                
                path.push_back(Giraffe[VertexPick][j]);
                

            }
        }
    }

    std::cout<< "Vertex:   Distance from Target\n";
    for (int i = 0; i < VerticeAmt; i++) {
        char nodeNumb = (char)('A' + i);
        std::cout<< nodeNumb<< "\t\t\t\t"<< distance[i]<<"Km" << std::endl;
        
    }

    std::cout << "\nRec Route:  \n";
    for (int i = 0; i < path.size(); i++) {
        char nodeNumb = (char)('A'+path.at(i));
        std::cout << nodeNumb <<"<- ";

    }
    


        /*int nearestNode = GetNearestNode();
        visited[nearestNode] = true;
        for (int j = 0; j < Vert; j++)
        {
            if (cost[nearestNode][j] != -1 &&
                distance[j] > distance[nearestNode] + cost[nearestNode][j])
            {
                distance[j] = distance[nearestNode] + cost[nearestNode][j];
                parentNode[j] = nearestNode;

            }
        }*/
   
}







//void PopulateNodes()
//{
//    for (int i = 0; i < Vert; i++)
//    
//    }
//    distance[source];
//
//
//}
//void DisplaySolution() {
  //  std::cout << "Node: \t\t\tCost: \t\t\tSource:";







int main()
{

    
    std::cout <<"Input Target Destination\n";
    int target = 0;

    std::cin >> target;

    //std::cout << "Input Current Location\n";

    int location = 0;

    //std::cin >> location;

    int graph[VerticeAmt][VerticeAmt] = 
   {//A B C D E F G H I J K L M N O P Q R S T U V W
     {0,6,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, //A
     {6,0,5,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, //B
     {0,5,0,7,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, //C
     {0,0,7,0,7,0,0,0,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, //D
     {0,0,0,7,0,0,0,0,6,0,0,0,0,15,0,0,0,0,0,0,0,0,0}, //E
     {5,0,0,0,0,0,8,0,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0}, //F
     {0,6,0,0,0,8,0,9,0,0,8,0,0,0,0,0,0,0,0,0,0,0,0}, //G
     {0,0,5,0,0,0,9,0,12,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, //H
     {0,0,0,8,6,0,0,12,0,0,0,0,10,0,0,0,0,0,0,0,0,0,0},//I
     {0,0,0,0,0,7,0,0,0,0,5,0,0,0,7,0,0,0,0,0,0,0,0}, //J
     {0,0,0,0,0,0,8,0,0,5,0,7,0,0,0,0,0,0,0,0,0,0,0}, //K
     {0,0,0,0,0,0,0,0,0,0,7,0,7,0,0,7,0,0,0,0,0,0,0}, //L
     {0,0,0,0,0,0,0,0,10,0,0,7,0,9,0,0,0,0,0,0,0,0,0}, //M
     {0,0,0,0,15,0,0,0,0,0,0,0,7,0,0,0,0,7,0,0,0,0,0}, //N
     {0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,13,0,0,9,0,0,0,0}, //O
     {0,0,0,0,0,0,0,0,0,0,0,7,0,0,13,0,8,0,0,0,11,0,0},//P
     {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,0,9,0,0,0,0,0,}, //Q
     {0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,9,0,0,0,0,0,10}, //R
     {0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,0,0,0,0,9,0,0,0}, //S
     {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,0,8,0,0}, //T
     {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11,0,0,0,8,0,8,0}, //U
     {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,0,5}, //V
     {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,10,0,0,0,5,0} //W

    };

    //std::cin >> source;
    //PopulateNodes();
    dijkstraAlg(graph, target);

    return 0;
}


