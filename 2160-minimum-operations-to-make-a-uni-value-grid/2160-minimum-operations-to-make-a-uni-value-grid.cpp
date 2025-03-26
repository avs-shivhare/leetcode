class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> ans;
        for(auto i: grid) {
            for(auto j: i) {
                ans.push_back(j);
            }
        }
        int op = 0;
        sort(ans.begin(),ans.end());
        int mid = ans.size()/2;
        for(auto i: ans) {
            int diff = abs(i-ans[mid]);
            if(diff %x == 0) {
                op += diff/x;
            }
            else return -1;
        }
        return op;
    }
};