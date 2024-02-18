// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long left =1;
        long right=n;
        while(left<=right){
            int mid=(left+right)/2;
            cout<<mid<<" ";
            if(isBadVersion(mid)==true && isBadVersion(mid-1)==false){
                    return mid;
            }
            else if(isBadVersion(mid)==false){
                  left=mid+1;
            }
            else if(isBadVersion(mid)==true && isBadVersion(mid-1)==true){
                right = mid-1;
            }
        }
        return -1;
    }
};