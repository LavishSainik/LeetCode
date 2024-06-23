class Solution {
public:
    
    class Pair{
      public:
        int r; int c; int dis;
        Pair(int r, int c, int dis){
             this->r =r;
             this->c=c;
             this->dis=dis;
        }
    };

   int dx[4] = {-1,1,0,0};
   int dy[4] = {0,0,-1,1};

    void connectedComp(int row, int col , vector<vector<bool>>& vis, vector<vector<int>>& grid){
        if(vis[row][col]==true || grid[row][col]==0){return;}
        vis[row][col]=true;
        grid[row][col]=-1;
        for(int i=0;i<4;i++){
            int newr = row + dx[i];
            int newc = col + dy[i];

            if(newr<0 || newc<0 || newr>=grid.size() || newc>=grid.size()){continue;}
            connectedComp(newr,newc,vis,grid);  
        }
    }

    int bfs(queue<Pair>& q, vector<vector<int>>& grid) {
        int n = grid.size();
        while (!q.empty()) {
            Pair p = q.front();
            q.pop();
            int currRow = p.r;
            int currCol = p.c;
            int currDis = p.dis;

            for (int i = 0; i < 4; ++i) {
                int newRow = currRow + dx[i];
                int newCol = currCol + dy[i];

                if (newRow < 0 || newCol < 0 || newRow >= n || newCol >= n) {
                    continue;
                }
                if (grid[newRow][newCol] == 1) {
                    return currDis; // Found the shortest path to the second island
                }
                if (grid[newRow][newCol] == 0) {
                    grid[newRow][newCol] = 2; // Mark as visited
                    q.push(Pair(newRow, newCol, currDis + 1));
                }
            }
        }
        return -1; // In case no path is found (shouldn't happen with valid input)
    }

    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> vis(n, vector<bool>(n,false));
        bool found=false;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    connectedComp(i, j, vis, grid);
                    found = true;
                    break;
                }
            }
            if (found) break;
        }
        queue<Pair> q;
        for(int i=0;i<grid.size();i++){
          for(int j=0;j<grid.size();j++){
            if(grid[i][j]==-1){
               q.push(Pair(i,j,0));
            }
          }
        }

        return bfs(q,grid);
    }
};