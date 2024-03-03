class Solution {
public:
    
    bool isPossible(vector<int> time,long long mid, int totalTrips){
         long long current_trip=0;
         for(int i=0;i<time.size();i++){
             if(time[i]<=mid){
                   current_trip+=mid/time[i];
             } 
         }
         return(current_trip>=totalTrips);
    }

    long long minimumTime(vector<int>& time, int totalTrips) {
        long long l=0;
        long long r=(long long)10e13;

        while(l<=r){
            long long mid = l+(r-l)/2;
            cout<<mid<<" ";
            if(isPossible(time,mid,totalTrips)==true){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return l;
    }
};