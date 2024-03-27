class Solution {
public:
    vector<vector<int>> ans;
    void find(vector<int> nums, int idx, vector<int> output){
             if(idx == nums.size()){
                ans.push_back(output);
                return;
             }
             output.push_back(nums[idx]);
             find(nums,idx+1,output);
              output.erase(output.end()-1);
             if(output.size()>0 && nums[idx]==output[output.size()-1]){
                  return;
             }
                find(nums,idx+1,output);
             
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> output;
        find(nums,0,output);
        sort(ans.begin(),ans.end());
        return ans;
    }
};