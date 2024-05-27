class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());
        int l = 0, r = piles.size()-2;
        int ans = 0;
        while(l<r) {
            ans += piles[r];
            l++;
            r -= 2;
        }
        return ans;
    }
};