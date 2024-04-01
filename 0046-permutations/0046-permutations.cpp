class Solution {
public:
    
    vector<vector<int>> ans;
    void find(vector<int> nums, vector<int> output, vector<bool> flag){
        //positive base case
        if(output.size()==nums.size()){
            ans.push_back(output);
            return;
        }

        for(int i=0;i<nums.size();i++){
            if(flag[i]==true){continue;}
            output.push_back(nums[i]);
            flag[i]=true;
            find(nums,output,flag);
            output.erase(output.end()-1);
            flag[i]=false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> flag(nums.size(),false);
       vector<int> output;
       find(nums,output,flag);
       return ans;
    }
};