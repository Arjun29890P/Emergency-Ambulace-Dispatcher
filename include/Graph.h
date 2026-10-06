#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <climits>

using namespace std;

class Graph
{
private:
    // Adjacency list: Location -> List of (Neighbor Location, Distance in km)
    unordered_map<string, vector<pair<string, int>>> adjList;

public:
    void addEdge(string u, string v, int weight);
    void displayGraph() const;
    
    // Dijkstra's Algorithm for finding the shortest path and distance
    pair<int, vector<string>> findShortestPath(string start, string destination);
};

#endif