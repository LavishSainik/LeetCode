class Solution {
public:
    
    bool isPossible(vector<int> bloomDay, int m, int k, int mid){       
            int made=0;
            int temp_count=0;
            for(int i=0;i<bloomDay.size();i++){
                
                if(bloomDay[i]-mid>0){
                 bloomDay[i]-=mid;}
                 else{bloomDay[i]=0;}
                 
                 if(i>0 && bloomDay[i-1]!=0){
                     temp_count=0;
                 }

                if(bloomDay[i]==0){
                    temp_count++;
                }
                if(temp_count==k){
                    temp_count=0;
                    made++;
                    
                }
            }
            cout<<made<<" ";
            return(made>=m);
    }

    int findMax(vector<int> bloomDay){
        
        int maxi=INT_MIN;
        for(int i=0;i<bloomDay.size();i++){
            maxi=max(maxi,bloomDay[i]);
        }
        return maxi;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long)m*k>bloomDay.size()){
            return -1;
        }
        long l=0;
        long r=findMax(bloomDay);

        while(l<=r){
            int mid=l+(r-l)/2;
            if(isPossible(bloomDay,m,k,mid)==true){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return l;
    }
};