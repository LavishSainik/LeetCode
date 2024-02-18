class Solution {
public:

   bool isWinner(vector<vector<char>> moves, int row , int cols, int ch){
            //if entire row of same character
            int count=0;
            for(int col=0;col<moves[0].size();col++){
                  if(moves[row][col]==ch){
                       count++;
                  }
                 
            }
             if(count==3){
                      return true;
             }
            //if entire column of same character
            count=0;
            for(int r=0;r<moves.size();r++){
                if(moves[r][cols]==ch){
                    count++;
                }
            }
            if(count==3){
                return true;
            }

            if(moves[0][0]==ch && moves[1][1]==ch && moves[2][2]==ch){
                return true;
            }
             if(moves[0][2]==ch && moves[1][1]==ch && moves[2][0]==ch){
                return true;
            }
            return false;
   }


    string tictactoe(vector<vector<int>>& moves) {
        char ch='X';
        vector<vector<char>> board(3,vector<char>(3));

        for(vector<int> move:moves){
            int row = move[0];
            int cols=move[1];
            board[row][cols]=ch;
            if(isWinner(board,row,cols,ch)==true){
                if(ch=='X'){return "A";}
                else{return "B";}
            }

            if(ch=='X'){ch='O';}
            else{ch='X';}

            
        }
        if(moves.size()==9){
            return "Draw";
        }
        else{
            return "Pending";
        }
        
    }
};