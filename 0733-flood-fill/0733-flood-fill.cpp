class Solution {
public:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};

    void dfs(int sr,int sc,int color,vector<vector<int>>& image,int prevColor){
        if(image[sr][sc]!=prevColor){return ;}
        image[sr][sc] = color;

        for(int i=0;i<4;i++){
            int newSr = sr + dx[i];
            int newSc = sc + dy[i];

            if(newSr<0 || newSc<0 || newSr>=image.size() || newSc>=image[0].size()){continue;}

            dfs(newSr,newSc, color, image, prevColor);
        }   
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
       int prevColor = image[sr][sc];
       if(prevColor == color){return image;}
       dfs(sr,sc,color,image,prevColor);
       return image;
    }
};