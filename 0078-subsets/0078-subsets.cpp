class Solution {
public:
    vector<vector<int>> result;

    void printSubsets(vector<int> nums, int idx, vector<int> output){
        if(idx==nums.size()){
            result.push_back(output);
            return;
        }
        output.push_back(nums[idx]);
        printSubsets(nums,idx+1,output);
        output.erase(output.end()-1);  //backtrackingl
        printSubsets(nums,idx+1,output);

    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> output;
         printSubsets(nums,0,output);
         sort(result.begin(),result.end());
         return result;
    }
};