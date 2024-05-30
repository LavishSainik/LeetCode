class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<int> stk;
        vector<int> ans(temp.size(),0);
        for(int i=0;i<temp.size();i++){
        while(!stk.empty() && temp[stk.top()]<temp[i]){
            int idx=stk.top();
            stk.pop();
            ans[idx] = i-idx;
        }
        stk.push(i);
    }
    return ans;
    }
};