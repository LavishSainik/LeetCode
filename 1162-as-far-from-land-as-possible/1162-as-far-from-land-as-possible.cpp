class Solution {
public:
    
    class Pair{
     public:
        int r; int c; int parentR; int parentC;
        Pair(int r, int c, int parentR, int parentC){
            this->r=r;
            this->c=c;
            this->parentR=parentR;
            this->parentC=parentC;
        }
    };
    
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};

    int bfs(vector<vector<int>>& grid,queue<Pair>& q){
        int maxDis=0;
        while(!q.empty()){
            Pair p = q.front();
            q.pop();
            int currRow = p.r;
            int currCol = p.c;
            int currParentRow = p.parentR;
            int currParentCol = p.parentC;
            int dis = abs(currRow-currParentRow) + abs(currCol-currParentCol);
            maxDis=max(dis,maxDis);

            for(int i=0;i<4;i++){
                int newR = currRow + dx[i];
                int newC = currCol + dy[i];

                if(newR<0 || newC<0 || newR>=grid.size() || newC>=grid.size() || grid[newR][newC]!=0){continue;}
                grid[newR][newC] = 2;
                q.push(Pair(newR,newC,currParentRow,currParentCol));
            }
           


        }
         return maxDis;
    }

    int maxDistance(vector<vector<int>>& grid) {
        queue<Pair> q;
        int n = grid.size();

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    q.push(Pair(i,j,i,j));
                }
            }
        }
        if(q.size()==0){return -1;}
        if(q.size()==n*n){return -1;}
        int ans =  bfs(grid,q);
        return ans;
    }
};