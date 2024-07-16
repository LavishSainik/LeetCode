class Solution {
public:

int solve(vector<int>& nums,int idx, int n, int prev, vector<vector<int>>& dp){
        if(idx==n+1){return 0;}
        if(dp[idx][prev]!=-1){return dp[idx][prev];}

        int yes = (prev==0)?(solve(nums,idx+1,n,1,dp)+nums[idx]):0;
        int no = solve(nums,idx+1,n,0,dp);

        return dp[idx][prev] = max(yes,no);
    }

    int rob(vector<int>& nums, int start, int end){
             vector<vector<int>> dp(nums.size()+1,vector<int>(2,-1));
             return solve(nums,start,end,0,dp);
    }

    int rob(vector<int>& nums) {
        if(nums.size()==1){return nums[0];}
         return max(rob(nums,0,nums.size()-2),rob(nums,1,nums.size()-1));
    }
};