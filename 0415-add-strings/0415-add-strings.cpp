class Solution {
public:
    string addStrings(string num1, string num2) {
           int p1 = num1.size()-1;
           int p2 = num2.size()-1;
           int carry =0;
           int maxi = max(p1,p2);
           vector<int> ans; 
           while(p1>=0 || p2>=0){
               int a;
               int b;
               if(p1<0 && p2>=0){
                   a=0;
               }
               else{
                   a = num1[p1]-'0';
               }
               if(p2<0 && p1>=0){
                   b=0;
               }
               else{
                 b=num2[p2]-'0';
               }
               int sum =0;
               sum = a+b+carry;
               carry = sum / 10;
               sum = sum %10;
               cout<<sum<<" ";
               ans.push_back(sum);
                if(p1<=0 && p2<=0 && carry>0){
                    ans.push_back(carry);
                }
               p1--;
               p2--;
              
           }
           string s;
           for(int i=ans.size()-1;i>=0;i--){
                  s.push_back(ans[i]+'0');
           }
           return s;
    }
};