class Solution {
public:
    long long maximumScore(vector<int>& nums, string s) {
        long long ans = 0;
        int n = s.size();
        priority_queue<vector<int>> q;
        for(int i = 0; i<n; i++) {
            if(s[i] == '1') {
                if(!q.empty() && q.top()[0] > nums[i]) {
                    ans += q.top()[0];
                    q.pop();
                    q.push({nums[i],i});
                }
                else {
                    ans += nums[i];
                }
            }
            else {
                q.push({nums[i],i});
            }
        }
        return ans;
    }
};