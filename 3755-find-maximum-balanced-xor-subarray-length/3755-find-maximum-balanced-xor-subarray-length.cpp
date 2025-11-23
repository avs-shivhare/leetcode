class Solution {
public:
    int find(vector<int> &arr,int l,int r) {
        int sum = arr[r];
        if(l > 0) sum -= arr[l-1];
        return sum;
    }
    int maxBalancedSubarray(vector<int>& nums) {
        map<pair<long long,int>,int> mpp;
        int n = nums.size();
        int cnt = 0;
        long long sum = 0;
        long long ans = 0;
        mpp[{0,0}] = -1;
        for(int i = 0; i<n; i++) {
            sum ^= nums[i];
            if(nums[i] & 1) cnt++;
            else cnt--;
            if(mpp.find({sum,cnt}) != mpp.end()) {
                ans = max(ans,1ll*i-mpp[{sum,cnt}]);
            }
            else mpp[{sum,cnt}] = i;
        }
        return ans;
    }
};