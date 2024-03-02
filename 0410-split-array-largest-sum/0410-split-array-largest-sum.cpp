class Solution {
public:

bool isPossible(vector<int> nums, int mid, int k){
      int split_req=1;
      int curr_sum=0;
      for(int i=0;i<nums.size();i++){
          if(curr_sum+nums[i]<=mid){
              curr_sum+=nums[i];
          }
          else{
              curr_sum=nums[i];
              split_req++;
          }
      }
      if(split_req<=k){
          return true;
      }
      return false;
}

int sum(vector<int> nums){
    int s=0;
    for(int i=0;i<nums.size();i++){
        s+=nums[i];
    }
    return s;
}
    int maxi(vector<int> nums){
        int m = INT_MIN;
         for(int i=0;i<nums.size();i++){
             m=max(nums[i],m);
         }
         return m;
    }

    int splitArray(vector<int>& nums, int k) {
        int l=maxi(nums);
        int r=sum(nums);

        while(l<=r){
            int mid = l+(r-l)/2;
            if(isPossible(nums,mid,k)==true){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return l;
    }
};