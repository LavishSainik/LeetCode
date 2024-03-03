class Solution {
public:
    
    bool isPossible(vector<int> nums, int threshold, int mid){
        int sum=0;
        for(int i=0;i<nums.size();i++){
            double x= nums[i];
            sum = sum + ceil(x/mid);
        }
        return(sum<=threshold);
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int l=1;
        int r=(long)10e6;
        while(l<=r){
            int mid = l+(r-l)/2;

            if(isPossible(nums,threshold,mid)==true){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return l;
    }
};