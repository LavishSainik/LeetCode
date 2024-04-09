class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            int ele = nums[i]*nums[i];
            ans.push_back(ele);
            for(int i=ans.size()-1;i>0;i--){
                if(ans[i]<ans[i-1]){
                    swap(ans[i],ans[i-1]);
                }
            }
        }
        return ans;
    }
};