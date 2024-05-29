class Solution {
public:
    int minDeletions(string s) {
        unordered_map<int,int> mpp;
        sort(s.begin(),s.end());
        int i = 0;
        int n = s.size();
        int ans = 0;
        while(i<n) {
            char prev = s[i];
            int len = 0;
            while(i<n && prev == s[i]) {
                len++;
                i++;
            }
            int curr = len;
            while(len != 0 && mpp.find(len) != mpp.end()) {
                len--;
            }
            mpp[len]++;
            ans += curr-len;
        }
        return ans;
    }
};