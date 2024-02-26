class Solution {
public:
    int mySqrt(int x) {
        long l=1;
        long r=x;
        while(l<=r){
            long m=l+(r-l)/2;

            if(m*m==x){
                return m;
            }
            else if(m*m>x){
                r=m-1;
            }
            else{
                l=m+1;
            }
        }
        return r;
    }
};