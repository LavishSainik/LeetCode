class Solution {
public:
    
    class Graph{
      public:
        vector<vector<int>> adjList;

        Graph(int n){
            adjList.resize(n);
        }

        void addEdges(vector<vector<int>>& connections){
            for(int i=0;i<connections.size();i++){
                adjList[connections[i][0]].push_back(connections[i][1]);
                adjList[connections[i][1]].push_back(connections[i][0]);
            }
        }

        void dfs(int src, vector<bool>& vis){
            if(vis[src]==true){return; }
            vis[src]=true;
            for(int i=0;i<adjList[src].size();i++){
                dfs(adjList[src][i],vis);
            }
        }
    };

    int makeConnected(int n, vector<vector<int>>& connections) {
        if(n-1>connections.size()){return -1;}
        Graph g(n);
        g.addEdges(connections);
        vector<bool>  vis(n, false);
        int components=0;
        for(int i=0;i<n;i++){
            if(vis[i]==true){continue;}
            g.dfs(i,vis);
            components++;
        }
        return components-1;
    }
};