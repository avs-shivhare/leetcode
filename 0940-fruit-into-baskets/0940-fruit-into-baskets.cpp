class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int ans = 0;
        int l = 0, r= 0;
        unordered_map<int,int> mpp;
        while(r<n) {
            mpp[fruits[r]]++;
            while(l<r && mpp.size() > 2) {
                mpp[fruits[l]]--;
                if(mpp[fruits[l]] == 0) mpp.erase(fruits[l]);
                l++;
            }
            if(mpp.size() <= 2) {
                ans = max(ans,r-l+1);
            }
            r++;
        }
        return ans;
    }
};