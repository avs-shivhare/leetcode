class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> ans;
        for(int i = 0; i+k<=n; i++) {
            int l = 0,r = 0;
            map<int,int> mpp;
            vector<int> temp;
            while(r<m) {
                for(int j = i; j-i<k; j++) {
                    mpp[grid[j][r]]++;
                }
                while(l<r && r-l+1 > k) {
                    for(int j = i; j-i<k; j++) {
                        mpp[grid[j][l]]--;
                        if(mpp[grid[j][l]] == 0) mpp.erase(grid[j][l]);
                    }
                    l++;
                }
                if(r-l+1 == k) {
                    int diff = INT_MAX;
                    int last = 1e9;
                    for(auto &j: mpp) {
                        if(last != 1e9) diff = min(diff,abs(last-j.first));
                        last = j.first;
                    }
                    if(diff == INT_MAX) temp.push_back(0);
                    else temp.push_back(diff);
                    //cout<<i<<" "<<l<<" "<<r<<" "<<diff<<endl;
                }
                r++;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};