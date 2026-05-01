class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        long long ans = 0;
        long long sum = 0;
        int n = nums.size();
        for(int i = 0; i<n; i++) {
            ans += 1ll*i*nums[i];
            if(i>0) sum += nums[i];
        }
        long long prev = ans;
        for(int i = 1; i<n; i++) {
            long long temp = prev-sum;
            temp += 1ll*(n-1)*nums[i-1];
            sum -= nums[i];
            sum += nums[i-1];
            ans = max(ans,temp);
            prev = temp;
        }
        return ans;
    }
};