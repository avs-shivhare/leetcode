class Solution {
public:
    int maxDepth(string s) {
       int maxi = 0;
       int cnt =0;
       for(char i: s) {
        if(i == '(') cnt++;
        else if(i == ')') cnt--;
        maxi = max(maxi,cnt);
       } 
       return maxi;
    }
};