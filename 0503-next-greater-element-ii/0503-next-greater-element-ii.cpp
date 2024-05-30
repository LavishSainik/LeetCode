class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> stk;
        vector<int> ans(nums.size(),-1);
        
        for(int i=0;i<2*nums.size();i++){
            while(!stk.empty() && nums[stk.top()%nums.size()]<nums[i%nums.size()]){
                int idx = stk.top();
                stk.pop();
                ans[idx%nums.size()] = nums[i%nums.size()];
            }
            stk.push(i%nums.size());
        }
        return ans;
    }
};