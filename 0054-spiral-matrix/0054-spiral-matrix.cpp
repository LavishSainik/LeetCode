class Solution {
public:

    

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int boundRow =matrix.size()-1;
        int boundCol = matrix[0].size()-1;
        int startRow = 0;
        int startCol=0;
        vector<int> ans;
        for(int i=0;i<=matrix[0].size()-1;i++){
            
            for(int col=startRow; col<=boundCol ; col++){
                 if(matrix[startRow][col]==INT_MIN){
                    return ans;
                }
                  ans.push_back(matrix[startRow][col]);
                  matrix[startRow][col]=INT_MIN;
            }
            
            
            for(int row=startCol+1;row<=boundRow;row++){
                  if(matrix[row][boundCol]==INT_MIN){
                    return ans;
                }
                ans.push_back(matrix[row][boundCol]);
                matrix[row][boundCol]=INT_MIN;
            }
          

            for(int col=boundCol-1; col>=startCol; col-- ){
                if(matrix[boundRow][col]==INT_MIN){
                    return ans;
                }
                ans.push_back(matrix[boundRow][col]);
                
                matrix[boundRow][col]=INT_MIN;
                
            }
            
            for(int row=boundRow-1;row>startRow;row--){
                 if(matrix[row][startCol]==INT_MIN){
                    return ans;
                }
                ans.push_back(matrix[row][startCol]);
                 
                matrix[row][startCol]=INT_MIN;
            }

            startRow++;
            startCol++;
            boundRow--;
            boundCol--;


        }
        return ans;
    }
};