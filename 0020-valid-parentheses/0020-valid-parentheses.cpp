class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
         if( s.size()==1){
            return false;
         }
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='[' ){
                stk.push(s[i]);
            }
            else{
                if(stk.empty()){
                    return false;
                }
                if((s[i]==')' && stk.top()=='(') || (s[i]=='}' && stk.top()=='{') || (s[i]==']'&& stk.top()=='[') ){   stk.pop();

                }
                else{
                    return false;
                }
            }
        }
        if(stk.empty()){
            return true;
        }
        return false;
    }
};