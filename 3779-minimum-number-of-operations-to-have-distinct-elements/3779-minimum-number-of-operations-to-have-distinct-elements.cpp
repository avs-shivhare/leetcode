class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> mpp;
        int cnt = 0;
        int n = nums.size();
        for(int i = 0; i<n; i++) {
            mpp[nums[i]]++;
            if(mpp[nums[i]] == 2) cnt++;
        }
        int ans = 0;
        int l = 0,r = 0;
        while(r<n) {
            if(cnt == 0) break;
            l = r;
            while(r<n && r-l+1 <= 3) {
                mpp[nums[r]]--;
                if(mpp[nums[r]] == 1) cnt--;
                r++;
            }
            ans++;
            l = r;
        }
        return ans;
    }
};