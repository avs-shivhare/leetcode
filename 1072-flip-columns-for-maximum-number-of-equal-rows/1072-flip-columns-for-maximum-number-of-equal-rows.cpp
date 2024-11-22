class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& mat) {
        map<vector<int>,int> mpp;
        int ans = 0;
        for(auto i: mat) {
            vector<int> temp;
            if(i[0]) temp = i;
            else {
                for(auto j: i) temp.push_back(j^1);
            }
            mpp[temp]++;
            ans = max(ans,mpp[temp]);
        }
        return ans;
    }
};