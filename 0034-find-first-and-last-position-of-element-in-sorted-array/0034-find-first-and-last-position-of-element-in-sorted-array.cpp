class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;

        int left =0;
        int right =nums.size()-1;
        while(left<=right){
           int mid = left+(right-left/2);
           if(nums[mid]==target){
               right=mid-1;
           }
           else if(nums[mid]>target){
               right=mid-1;
           }
           else{
               left=mid+1;
           }
        }
        if(left<nums.size() && nums[left]==target){
            ans.push_back(left);
        }
        else{
            ans.push_back(-1);
        }
    
       left=0;
       right=nums.size()-1;

       while(left<=right){
           int mid = left+(right-left/2);
           if(nums[mid]==target){
               left=mid+1;
           }
           else if(nums[mid]>target){
               right=mid-1;
           }
           else{
               left=mid+1;
           }
       }
       if(right>-1 && nums[right]==target){
            ans.push_back(right);
        }
        else{
            ans.push_back(-1);
        }
    return ans;
    }
};