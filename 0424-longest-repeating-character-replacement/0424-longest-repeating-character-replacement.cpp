class Solution {
public:
    int characterReplacement(string s, int k) {
        int l =0,r=0;
        int ans = 0;
        int n = s.size();
        int maxi = 0;
        vector<int> mpp(26,0);
        while(r<n) {
            mpp[s[r]-'A']++;
            maxi = max(maxi,mpp[s[r]-'A']);
            if(r-l+1 - maxi > k) {
                mpp[s[l]-'A']--;
                l++;
            }
            if(r-l+1-maxi <= k)ans = r-l+1;
            r++;
        }
        return ans;
    }
};