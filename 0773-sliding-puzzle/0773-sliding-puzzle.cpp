class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string start="";
        string target="123450";

        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                start += to_string(board[i][j]);
            }
        }
        queue<pair<string,int>> q;
        unordered_set<string> vis;
        q.push({start,start.find('0')});
        vis.insert(start);
        vector<vector<int>> directions = {{1,3},{0,2,4},{1,5},{0,4},{1,3,5},{2,4}};
        int moves=0;
        
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                auto [currStr,zeroPos] = q.front();
                q.pop();

                if(currStr==target){return moves;}

                for(int dir: directions[zeroPos]){
                    string next = currStr;
                    swap(next[zeroPos],next[dir]);
                    if(vis.find(next)==vis.end()){
                         q.push({next,dir});
                         vis.insert(next);
                    }
                }
            }
            ++moves;
        }
     return -1;

    }
};