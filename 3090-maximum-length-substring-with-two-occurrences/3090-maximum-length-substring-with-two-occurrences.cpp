class Solution {
public:
    int maximumLengthSubstring(string s) {
        int l = 0, r = 0;
        int n = s.size();
        unordered_map<int,int> mpp;
        int cnt = 0,ans = 0;
        while(r<n) {
            if(mpp[s[r]] == 2) cnt++;
            mpp[s[r]]++;
            while(l<r && cnt > 0) {
                mpp[s[l]]--;
                if(mpp[s[l]] == 2) cnt--;
                l++;
            }
            if(cnt == 0) ans = max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};