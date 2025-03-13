class Solution {
public:
    bool check(vector<int> &nums,int mid,vector<vector<int>> &queries) {
        int n = nums.size();
        vector<int> temp(n+1,0);
        for(int i = 0; i<=mid; i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            int val = queries[i][2];
            temp[l] += val;
            temp[r+1] -= val;
        }
        int sum = 0;
        for(int i = 0; i<n; i++) {
            sum += temp[i];
            if(nums[i]-sum > 0) return false;
        }
        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int l = 0,r = queries.size()-1;
        if(check(nums,-1,queries)) return 0;
        int ans = -1;
        while(l<=r) {
            int mid = (l+r)>>1;
            //cout<<mid<<endl;
            if(check(nums,mid,queries)) {
                ans = mid+1;
                r = mid-1;
            }
            else l = mid+1;
        }
        return ans;
    }
};