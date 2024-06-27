class Solution {
public:
   
     void dfs(vector<vector<int>>& matrix, vector<vector<bool>>& visited, int i, int j) {
        visited[i][j] = true;
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for (auto dir : directions) {
            int ni = i + dir.first, nj = j + dir.second;
            if (ni >= 0 && ni < matrix.size() && nj >= 0 && nj < matrix[0].size() &&
                !visited[ni][nj] && matrix[ni][nj] >= matrix[i][j]) {
                dfs(matrix, visited, ni, nj);
            }
        }
    }
   
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<bool>> pacific(m,vector<bool>(n,false));
       vector<vector<bool>> atlantic(m,vector<bool>(n,false));

        for(int i=0;i<m;i++){
            dfs(heights,pacific,i,0);
            dfs(heights,atlantic,i,n-1);
        }

        for(int j=0;j<n;j++){
            dfs(heights,pacific,0,j);
            dfs(heights,atlantic,m-1,j);
        }

        vector<vector<int>> results;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pacific[i][j] && atlantic[i][j]){
                    results.push_back({i,j});
                }
            }
        }

        return results;

    }
};