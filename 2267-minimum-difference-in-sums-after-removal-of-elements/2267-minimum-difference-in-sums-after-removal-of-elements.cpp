class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefix(n,0),suffix(n,0);
        priority_queue<long long> maxi;
        priority_queue<long long,vector<long long>,greater<long long>> mini;
        long long sum = 0;
        for(int i = 0; i<n; i++) {
            if(maxi.size() < n/3) {
                maxi.push(nums[i]);
                sum += nums[i];
            }
            else if(maxi.top() > nums[i]) {
                sum -= maxi.top();
                maxi.pop();
                sum += nums[i];
                maxi.push(nums[i]);
            }
            if(maxi.size() == n/3) prefix[i] = sum;
        }
        sum = 0;
        for(int i = n-1; i>=0; i--) {
            if(mini.size() < n/3) {
                sum += nums[i];
                mini.push(nums[i]);
            }
            else if(mini.top() < nums[i]) {
                sum -= mini.top();
                mini.pop();
                mini.push(nums[i]);
                sum += nums[i];
            }
            if(mini.size() == n/3) suffix[i] = sum;
        }
        long long ans = 1e18;
        for(int i = n/3; i<(n/3)*2; i++) {
            ans = min({prefix[i]-suffix[i+1],ans,prefix[i-1]-suffix[i]});
        }
        return ans;
    }
};