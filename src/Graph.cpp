#include "../include/Graph.h"
#include <queue>
#include <algorithm>

void Graph::addEdge(string u, string v, int weight)
{
    adjList[u].push_back({v, weight});
    adjList[v].push_back({u, weight}); // Assuming a bidirectional road network
}

void Graph::displayGraph() const
{
    cout << "\n========== CITY ROAD NETWORK (GRAPH) ==========\n";
    if (adjList.empty())
    {
        cout << "No road network data available.\n";
        return;
    }

    for (auto const& pair : adjList)
    {
        cout << pair.first << " ---> ";
        for (auto const& neighbor : pair.second)
        {
            cout << "[" << neighbor.first << " (" << neighbor.second << " km)] ";
        }
        cout << endl;
    }
}

pair<int, vector<string>> Graph::findShortestPath(string start, string destination)
{
    unordered_map<string, int> distances;
    unordered_map<string, string> previousNodes;
    
    // Min-heap priority queue for Dijkstra: {distance, node}
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;

    for (auto const& pair : adjList)
    {
        distances[pair.first] = INT_MAX;
    }

    distances[start] = 0;
    pq.push({0, start});

    while (!pq.empty())
    {
        int currentDist = pq.top().first;
        string currentNode = pq.top().second;
        pq.pop();

        if (currentNode == destination)
            break;

        if (currentDist > distances[currentNode])
            continue;

        for (auto const& neighbor : adjList[currentNode])
        {
            string nextNode = neighbor.first;
            int weight = neighbor.second;

            if (distances[currentNode] + weight < distances[nextNode])
            {
                distances[nextNode] = distances[currentNode] + weight;
                previousNodes[nextNode] = currentNode;
                pq.push({distances[nextNode], nextNode});
            }
        }
    }

    // Reconstruct the shortest path
    vector<string> path;
    string curr = destination;
    
    if (distances[destination] == INT_MAX)
    {
        return {INT_MAX, {}}; // No path found
    }

    while (previousNodes.find(curr) != previousNodes.end())
    {
        path.push_back(curr);
        curr = previousNodes[curr];
    }
    path.push_back(start);
    reverse(path.begin(), path.end());

    return {distances[destination], path};
}