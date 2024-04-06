class Solution {
public:
    vector<vector<string>> ans;
    void find(vector<vector<bool>> chess, int row, int n){
        //base case
        if(row==n){
            addOutput(chess);
            return;
        }

        //choices
        for(int col=0;col<n;col++){
            if(isQueenSafe(chess, row, col, n) != true){
                  continue;
            }
            chess[row][col]=true;
            find(chess,row+1,n);
            chess[row][col]=false; //backtracking
        }
    }

    void addOutput(vector<vector<bool>> chess){
        vector<string> preAns;
        for(int i=0;i<chess.size();i++){
            string str="";
            for(int j=0;j<chess[0].size();j++){
                if(chess[i][j]==true){
                    str += 'Q';
                }
                else{
                    str+='.';
                }
            }
             preAns.push_back(str);
        }
        ans.push_back(preAns);
        return;
    }

   bool isQueenSafe(vector<vector<bool>> chess, int row, int col, int n){
        //checking saftey at top
        for(int i=row;i>=0;i--){
            if(chess[i][col]==true){
                return false;
            }
        }

        //at top right
        for(int r=row,c=col; r>=0 && c<n ; r--,c++){
             if(chess[r][c]==true){
                return false;
             }
        }

        //at top left
        for(int r=row,c=col; r>=0 && c>=0; r--,c--){
            if(chess[r][c]==true){
                return false;
            }
        }
        return true;
   }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<bool>> chess(n,vector<bool> (n));
        find(chess, 0, n);
        return ans;
    }
};