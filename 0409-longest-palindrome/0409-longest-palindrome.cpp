class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.size();
        unordered_map<char,int> mpp;
        for(int i =0; i<n; i++) {
            mpp[s[i]]++;
        }
        int ans = 0;
        int once = 0;
        for(auto i: mpp) {
            if(i.second & 1) {
                ans += i.second-1;
                once++;
            }
            else ans += i.second;
        }
        if(once) ans++;
        return ans;
    }
};