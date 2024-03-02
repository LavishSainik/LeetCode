class Solution {
public:
    
    bool isPossible(vector<int> piles, int available_hours, int k){
          double hours_spend = 0;
          for(int i=0; i<piles.size();i++){
              double current_piles = piles[i];
               double hoursToEatCurrentPile = ceil(current_piles/k);
              hours_spend += hoursToEatCurrentPile;
          }
          if(hours_spend<=available_hours){
              return true;
          }
          return false;
    }
    
    int findmax(vector<int> nums){
          int maxi=INT_MIN;
          for(int i=0;i<nums.size();i++){
              if(nums[i]>maxi){
                  maxi=nums[i];
              }
          }
          return maxi;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int l=0;
        int r = findmax(piles);
        int mini = INT_MAX;
        while(l<=r){
            int m = l+(r-l)/2;
            if(isPossible(piles,h,m)==true){
                mini = min(mini,m);
                r=m-1;
            }
            else{
                l=m+1;
            }

            
                    }
        return mini;
    }
};