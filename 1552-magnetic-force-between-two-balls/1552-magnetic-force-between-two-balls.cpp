class Solution {
public:

bool isPossible(int mid,vector<int> stalls,int k){
      int curr_cows=1;
      
      int prev=0;
      for(int i=0;i<stalls.size();i++){
          if(stalls[i]-stalls[prev]>=mid){
              curr_cows++;
              prev=i;
           }
      }
      return(curr_cows>=k);

}


    int maxDistance(vector<int>& stalls, int k) {
        sort(stalls.begin(),stalls.end());
        int l=0;
        int r=stalls[stalls.size()-1]-stalls[0];

        while(l<=r){
            int mid=(l+r)/2;
            if(isPossible(mid,stalls,k)==true){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
           
        }
         return r;

    }
};