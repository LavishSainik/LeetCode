class Solution {
public:

    bool isRowValid(vector<vector<char>> board , int row){
            vector<int> freq(9,0);
            for(int cols=0;cols<9;cols++){
                if(board[row][cols]=='.' || board[row][cols]==','){continue;}
                 freq[(board[row][cols]-'0')-1]++;
                if(freq[(board[row][cols]-'0')-1]  >1){
                    return false;
                }
            }
            return true;
    }

    bool isColumnValid(vector<vector<char>> board,int col){
            vector<int> freq(9,0);
            for(int r=0;r<9;r++){
                 if(board[r][col]=='.' || board[r][col]==','){continue;}
                 freq[  (  board[r][col] - '0') - 1 ]++;
                if(freq[  (  board[r][col] - '0') - 1 ]>1){
                    return false;
                }
            }
            return true;
    }

    bool isSubGridValid(vector<vector<char>>& board,int row,int col){
        vector<int> freq(9,0);
           for(int i=row;i<row+3;i++){
               for(int j=col;j<col+3;j++){
                     if(board[i][j]=='.' || board[i][j]==','){continue;}
                   cout<<board[i][j]<<" ";
                    freq[  (  board[i][j] - '0') - 1 ]++;
                if(freq[  (  board[i][j] - '0') - 1 ]>1){
                    return false;
                }
               }
           }
           return true;
    }
    

    bool isValidSudoku(vector<vector<char>>& board) {
        for(int row=0;row<9;row++){
            if(isRowValid(board,row)==false){
                return false;
            }
        }
        for(int col=0;col<9;col++){
            if(isColumnValid(board,col)==false){
                return false;
            }
        }

        for(int row=0; row<9; row+=3){
            for(int col=0; col<9; col+=3){
                if(isSubGridValid(board,row,col)==false){
                    return false;
                }
            }
        }

        return true;
    }
};