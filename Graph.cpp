#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;
// Class to represent the Flight Network Graph
class FlightGraph {
    // Adjacency list: City -> List of (Destination City, Flight Time in hours)
    map<string, vector<pair<string, float>>> adjList;
public:
    // Function to add a directed flight path between two cities with a cost (time)
    void addFlight(string u, string v, float time) {
        adjList[u].push_back({v, time});
    }
    // Function to display the Adjacency List
    void displayAdjacencyList() {
        cout << "\n--- Flight Network Adjacency List ---\n";
        for (auto pair : adjList) {
            cout << pair.first << " -> ";
            for (auto neighbor : pair.second) {
                cout << "[" << neighbor.first << ", " << neighbor.second << " hrs] ";
            }
            cout << endl;
        }
    }
    // Helper function for DFS traversal
    void DFS(string currentCity, set<string>& visited) {
        visited.insert(currentCity); // Mark current city as visited
        cout << currentCity << " -> ";
        // Visit all unvisited neighbors
        for (auto neighbor : adjList[currentCity]) {
            string nextCity = neighbor.first;
            if (visited.find(nextCity) == visited.end()) {
                DFS(nextCity, visited);
            }
        }
    }
    // Function to check graph connectivity starting from a source city
    bool checkConnectivity(string startCity, int totalCities) {
        set<string> visited;
 cout << "\nDFS Traversal starting from " << startCity << ":\n";
        DFS(startCity, visited);
        cout << "END\n";
        // If the number of visited cities equals the total cities, the graph is connected (from this start point)
        if (visited.size() == totalCities) {
            cout << "\nResult: All " << totalCities << " cities are reachable! The graph is connected.\n";
            return true;
        } else {
            cout << "\nResult: Only " << visited.size() << " out of " << totalCities << " cities are reachable. Graph is not fully connected.\n";
            return false;
        }
    }
};
int main() {
    FlightGraph network;
    // Total number of cities in our network
    int totalCities = 5;
    // Adding flight paths based on the exemplar
    // Mumbai connected to Delhi (2.0 hrs) and Pune (0.5 hrs)
    network.addFlight("Mumbai", "Delhi", 2.0);
    network.addFlight("Mumbai", "Pune", 0.5);
    // Delhi connected to Bangalore (2.5 hrs)
    network.addFlight("Delhi", "Bangalore", 2.5);
    // Pune connected to Bangalore (1.5 hrs)
    network.addFlight("Pune", "Bangalore", 1.5);
    // Bangalore connected to Chennai (1.0 hrs)
    network.addFlight("Bangalore", "Chennai", 1.0);
    // 1. Display the Adjacency List representation
    network.displayAdjacencyList();
    // 2. Perform DFS and check connectivity starting from Mumbai
    network.checkConnectivity("Mumbai", totalCities);
    return 0;
}
