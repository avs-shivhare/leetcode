class Solution {
public:
    int minFlips(string s) {
        int ans = 1e9;
        int o = 0,z = 0;
        int n = s.size();
        bool flag = false;
        if(s[0] == s[n-1] && s[0] == '1' && n > 1) flag = true;
        vector<int> prefix0(n,0),prefix1(n,0),suffix0(n,0),suffix1(n,0);
        for(int i = 1; i<n; i++) {
            if(s[i-1] == '0') z++;
            else o++;
            prefix0[i] = z;
            prefix1[i] = o;
        }
        o = 0,z = 0;
        for(int i = n-2; i>=0; i--) {
            if(s[i+1] == '0') z++;
            else o++;
            suffix0[i] = z;
            suffix1[i] = o;
        }
        for(int i = 0; i<n; i++) {
            if(s[i] == '0') ans = min({ans,max(prefix1[i]+suffix1[i]-(flag ? 2 : 1),0),prefix0[i]+suffix0[i]+1});
            else ans = min({ans,prefix0[i]+suffix0[i],max(0,prefix1[i]+suffix1[i]-(flag ? 1 : 0))});
        }
        return ans;
    }
};