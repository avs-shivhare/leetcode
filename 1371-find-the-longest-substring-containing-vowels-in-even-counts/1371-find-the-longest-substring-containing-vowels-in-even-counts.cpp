class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n = s.size();
        int ans =0;
        unordered_map<int,int> mpp;
        int mask =0;
        mpp[0] = -1;
        for(int i =0; i<n; i++) {
            if(s[i] == 'a') mask ^= 1;
            else if(s[i] == 'e') mask ^= 2;
            else if(s[i] == 'i') mask  ^= 4;
            else if(s[i] == 'o') mask ^= 8;
            else if(s[i] == 'u') mask ^= 16;
            if(mpp.count(mask)) {
                ans = max(ans,i-mpp[mask]);
            }
            else {
                mpp[mask] = i;
            }
        }
        return ans;
    }
};