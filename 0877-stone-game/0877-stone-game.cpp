class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int l = 0, r = piles.size()-1;
        int sum = 0,sum2 = 0;
        bool flag = true;
        while(l<=r) {
            if(flag) {
                if(piles[l] < piles[r]) sum += piles[r--];
                else sum += piles[l++];
            }
            else {
                if(piles[l] < piles[r]) sum2 += piles[r--];
                else sum2 += piles[l++];
            }
            if(sum > sum2) return true;
            flag = !flag;
        }
        return false;
    }
};