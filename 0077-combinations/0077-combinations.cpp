class Solution {
public:
     vector<vector<int>> ans;
     void find(int n, int k, vector<int> output){

         //positive base case
         if(k==0){
            ans.push_back(output);
            return;
         }

         //negative base case
         if(n==0 || k>n){
            return;
         }

         output.push_back(n);
         find(n-1,k-1,output);
         output.erase(output.end()-1); //backtracking
         find(n-1,k,output);
     }

    vector<vector<int>> combine(int n, int k) {
        vector<int> output;
        find(n,k,output);
        return ans;
    }
};