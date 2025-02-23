class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        long long ans = 0;
        priority_queue<pair<long long,int>> q;
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                q.push({grid[i][j],i});
            }
        }
        vector<int> row(n,0);
        while(!q.empty() && k) {
            auto num = q.top().first;
            int r = q.top().second;
            q.pop();
            if(row[r] < limits[r]) {
                row[r]++;
                ans += num;
                k--;
            }
        }
        return ans;
    }
};