class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int l = 0,r = 0;
        unordered_map<int,int> mpp;
        int cnt = 0,ans = 0;
        while(r<n) {
            if(mpp[s[r]] == 0) cnt++;
            mpp[s[r]]++;
            while(l<=r && cnt >= 3) {
                ans += n-r;
                mpp[s[l]]--;
                if(mpp[s[l]] == 0) cnt--;
                l++;
            }
            r++;
        }
        return ans;
    }
};