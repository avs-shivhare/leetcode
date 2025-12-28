class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        long long ans = -1e18;
        priority_queue<vector<long long>,vector<vector<long long>>,greater<vector<long long>>> q;
        long long sum = 0;
        int n = nums.size();
        for(int i = 0; i<n; i++) {
            q.push({nums[i],i});
        }
        for(int i = 0; i<n-1; i++) {
            sum += nums[i];
            while(!q.empty() && q.top()[1] <= i) q.pop();
            ans = max(ans,sum-q.top()[0]);
        }
        return ans;
    }
};