class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        int m = baskets.size();
        int cnt = 0;
        for(auto i: fruits) {
            bool flag = false;
            for(int j = 0; j<m; j++) {
                if(baskets[j] >= i) {
                    flag = true;
                    baskets[j] = 0;
                    break;
                }
            }
            if(!flag) cnt++;
        }
        return cnt;
    }
};