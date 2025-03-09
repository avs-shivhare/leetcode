class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        int ans = 0;
        for(auto i: fruits) {
            bool flag = false;
            for(auto &j: baskets) {
                if(j>= i) {
                    j = 0;
                    flag = true;
                    break;
                }
            }
            if(!flag) ans++;
        }
        return ans;
    }
};