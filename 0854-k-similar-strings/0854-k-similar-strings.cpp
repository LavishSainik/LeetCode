class Solution {
public:
    int kSimilarity(string s1, string s2) {
        queue<pair<string,int>> q;
        unordered_set<string> vis;
         
        q.push({s1,0});
        vis.insert(s1);

        while(!q.empty()){
            auto [currStr,swaps] = q.front();
            q.pop();
            
            if(currStr==s2){
                return swaps;
            }

           int idx=0;
           for(int i=0;i<s1.size();i++){
              if(currStr[i]!=s2[i]){
                idx=i;
                break;
              }
           }
           
           for(int i=idx+1;i<s2.size();i++){
             if(currStr[i]==s2[idx] && currStr[i]!=s2[i]){
                string next = currStr;
                swap(next[i],next[idx]);
             
             if(vis.find(next)==vis.end()){
                q.push({next,swaps+1});
                vis.insert(next);
             }
           }
           }
        }
        return -1;

    }
};