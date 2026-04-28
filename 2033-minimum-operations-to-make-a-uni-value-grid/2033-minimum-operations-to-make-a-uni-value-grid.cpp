class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> temp;
        for(auto &i: grid) {
            for(auto &j: i) {
                temp.push_back(j);
            }
        }
        sort(temp.begin(),temp.end());
        int mid = temp.size()/2;
        int ans = 0;
        for(auto &i: temp) {
            if(abs(i-temp[mid])%x != 0) return -1;
            ans += abs(i-temp[mid])/x;
        }
        return ans;
    }
};