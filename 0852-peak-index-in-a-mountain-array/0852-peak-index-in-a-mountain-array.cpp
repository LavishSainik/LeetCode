class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l=0;
        int r=arr.size()-1;

        while(l<=r){
            int m=l+(r-l)/2;

            if(m-1>=0 && arr[m]>arr[m-1]){
               
                if(arr[m]>arr[m+1]){
                    return m;
                }
                else{
                l=m+1;}
            }
            else if(m-1<0){
                  l=1;
            }
            else{
                r=m-1;
            }
        }
        return r;

    }
};