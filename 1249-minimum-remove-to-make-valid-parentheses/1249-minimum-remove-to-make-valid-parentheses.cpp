class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size();
        int open =0,close = 0;
        for(int i =0; i<n; i++) {
            if(s[i] == '(') open++;
            else if(s[i] == ')') close++;
            if(close > open) {
                s.erase(s.begin()+i);
                close--;
                i--;
            }
        }
        if(open > close) {
            for(int i =n-1; i>=0; i--) {
                if(s[i] == '(') {
                    s.erase(s.begin()+i);
                    open--;
                    i++;
                }
                if(open == close) break;
            }
        }
        return s;
    }
};