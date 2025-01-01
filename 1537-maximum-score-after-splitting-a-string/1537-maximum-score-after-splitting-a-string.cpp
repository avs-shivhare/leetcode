class Solution {
public:
    int maxScore(string s) {
        int one = 0,zero = 0;
        int ans = 0;
        for(auto i: s) {
            if(i == '1') one++;
        }
        int n = s.size();
        for(int i = 0; i<n-1; i++) {
            if(s[i] == '0') zero++;
            else one--;
            ans = max(ans,one+zero);
        }
        return ans;
    }
};