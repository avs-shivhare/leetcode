class Solution {
public:
    string lexSmallest(string s) {
        string ans = s;
        reverse(s.begin(),s.end());
        ans = min(s,ans);
        reverse(s.begin(),s.end());
        int n = s.size();
        for(int i = 0; i<n; i++) {
            reverse(s.begin(),s.begin()+i+1);
            ans = min(ans,s);
            reverse(s.begin(),s.begin()+i+1);
            int last = n-i-1;
            reverse(s.begin()+last,s.end());
            ans = min(ans,s);
            reverse(s.begin()+last,s.end());
        }
        return ans;
    }
};