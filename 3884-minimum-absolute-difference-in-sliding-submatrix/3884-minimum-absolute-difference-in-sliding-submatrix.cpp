class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> ans;
        for(int i = 0; i<n; i++) {
            if(i+k > n) break; 
            vector<int> temp;
            int l = 0,r = 0;
            map<int,int> mpp;
            while(r<m) {
                for(int j = i; j<i+k; j++) {
                    mpp[grid[j][r]]++;
                }
                while(l<r && r-l+1 > k) {
                    for(int j = i; j<i+k; j++) {
                        mpp[grid[j][l]]--;
                        if(mpp[grid[j][l]] == 0) mpp.erase(grid[j][l]);
                    }
                    l++;
                }
                if(r-l+1 == k) {
                    int mini = 1e9;
                    int last = -1e9;
                    for(auto i: mpp) {
                        if(last != -1e9) {
                            mini = min(mini,abs(i.first-last));
                        }
                        last = i.first;
                    }
                    if(mini >= 1e9) mini = 0;
                    temp.push_back(mini);
                }  
                r++;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};