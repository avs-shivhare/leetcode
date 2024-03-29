class Solution {
public:
    int characterReplacement(string s, int k) {
        int l =0,r=0;
        int ans = 0;
        int n = s.size();
        int maxi = 0;
        unordered_map<char,int> mpp;
        while(r<n) {
            mpp[s[r]]++;
            maxi = max(maxi,mpp[s[r]]);
            if(r-l+1 - maxi > k) {
                mpp[s[l]]--;
                if(mpp[s[l]] == 0) mpp.erase(s[l]);
                l++;
            }
            if(r-l+1-maxi <= k)ans = r-l+1;
            r++;
        }
        return ans;
    }
};