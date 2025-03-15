class Solution {
public:
    bool check(vector<int> &nums,int &k,long long &mid) {
        int last = -2;
        int cnt = 0;
        int n = nums.size();
        for(int i = 0; i<n; i++) {
            if(nums[i] <= mid && i-last > 1) {
                last = i;
                cnt++;
            }
        }
        return cnt >= k;
    }
    int minCapability(vector<int>& nums, int k) {
        long long l = 0,r = *max_element(nums.begin(),nums.end());
        int ans = r;
        while(l<=r) {
            long long mid = (l+r)>>1;
            if(check(nums,k,mid)) {
                ans = mid;
                r = mid-1;
            }
            else l = mid+1;
        }
        return ans;
    }
};