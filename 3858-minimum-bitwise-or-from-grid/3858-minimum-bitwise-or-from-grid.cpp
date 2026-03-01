class Solution {
public:
    bool check(vector<vector<int>> &grid,int k) {
        for(auto &i: grid) {
            bool flag = false;
            for(auto &j: i) {
                if((j&k) == 0) flag = true;
            }
            if(!flag) return false;
        }
        return true;
    }
    int minimumOR(vector<vector<int>>& grid) {
        long long ans = 0;
        int temp = 0;
        for(int i = 31; i>=0; i--) {
            int t = temp|(1<<i);
            if(check(grid,t)) {
                temp |= 1<<i;
            }
            else ans |= 1<<i;
        }
        return ans;
    }
};