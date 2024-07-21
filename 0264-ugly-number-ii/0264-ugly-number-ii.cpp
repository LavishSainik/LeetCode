class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n+1,-1);
        dp[0] = 1;
        // maintaining 3 pointers with index
        
        int ptr1 = 0;
        int ptr2 = 0;
        int ptr3 = 0;

        for(int i=1;i<n+1;i++){
            int a = dp[ptr1]*2;
            int b = dp[ptr2]*3;
            int c = dp[ptr3]*5;

            int mini = min(a,min(b,c));

            if(mini==a){
                dp[i]=a;
                ptr1++;
            }
           if(mini==b){
                dp[i]=b;
                ptr2++;
            }
            if(mini==c){
                dp[i]=c;
                ptr3++;
            }
        }
        return dp[n-1];

    }
};