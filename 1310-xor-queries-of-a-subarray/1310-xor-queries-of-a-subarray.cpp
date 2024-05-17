class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int xr = 0;
        int n = arr.size();
        // precompute xor of every index
        for(int i =0; i<n; i++) {
            xr ^= arr[i];
            arr[i] = xr;
        }
        int m = queries.size();
        vector<int> ans(m,0);
        // finding answer of any queries by range precompute answer xor range answer
        for(int i =0; i<m; i++) {
            int left = queries[i][0];
            int right = queries[i][1];
            int pre = 0;
            if(left-1 >= 0) pre = arr[left-1];
            ans[i] = pre^arr[right];
        }
        return ans;
    }
};