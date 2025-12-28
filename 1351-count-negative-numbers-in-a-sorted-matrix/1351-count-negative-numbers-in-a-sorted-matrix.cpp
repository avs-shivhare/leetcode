class Solution {
public:
    int find(vector<int> &arr) {
        int l = 0, r = arr.size()-1;
        int ans = arr.size();
        while(l<=r) {
            int mid = (l+r)>>1;
            if(arr[mid] < 0) {
                ans = mid;
                r = mid-1;
            }
            else l = mid+1;
        }
        return ans;
    }
    int countNegatives(vector<vector<int>>& grid) {
        int cnt = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i<n; i++) {
            cnt += m-find(grid[i]);
        }
        return cnt;
    }
};