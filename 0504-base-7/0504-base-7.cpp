class Solution {
public:
    string convertToBase7(int num) {
        int res = 0;
        int power=1;
        while(num!=0){
            int remainder = num%7;
             res = res + remainder*power;
            num=num/7;
            power = power*10;
        }
        
        return to_string(res);
    }
};