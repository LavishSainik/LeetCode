#include <vector>
#include <queue>
#include <utility>
#include <climits>
#include <iostream>

using namespace std;

class Solution {
public:
    // Define the Pair class with comparison operator overloaded
    class Pair {
    public:
        int time;
        int node;

        Pair(int time, int node) {
            this->time = time;
            this->node = node;
        }

        bool operator>(const Pair& other) const {
            return this->time > other.time;
        }
    };

    // Define the Graph class to handle adjacency list
    class Graph {
    public:
        vector<vector<pair<int, int>>> adj;

        Graph(int n) {
            adj.resize(n + 1);  // Initialize with n+1 to handle 1-indexed nodes
        }

        void addEdge(int src, int dest, int wt) {
            adj[src].emplace_back(dest, wt);
        }
    };

    // Implement the network delay time function
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        Graph g(n);  // Initialize Graph with n nodes
        for (int i = 0; i < times.size(); i++) {
            g.addEdge(times[i][0], times[i][1], times[i][2]);  // Add edges
        }

        priority_queue<Pair, vector<Pair>, greater<Pair>> pq;
        vector<int> vis(n + 1, INT_MAX);
        
        // k is the source node
        pq.emplace(0, k);
        vis[k] = 0;

        while (!pq.empty()) {
            Pair p = pq.top();
            int currTime = p.time;
            int currNode = p.node;
            pq.pop();

            if (vis[currNode] < currTime) {
                continue;
            }

            for (const auto& neighbour : g.adj[currNode]) {
                int nbrNode = neighbour.first;
                int nbrTime = neighbour.second;

                if (vis[currNode] + nbrTime < vis[nbrNode]) {
                    vis[nbrNode] = vis[currNode] + nbrTime;
                    pq.emplace(Pair(vis[nbrNode], nbrNode));
                }
            }
        }

        int maxTime = *max_element(vis.begin() + 1, vis.end());
        return maxTime == INT_MAX ? -1 : maxTime;
    }
};
