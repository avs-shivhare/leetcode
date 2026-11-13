class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefix(n+1,0);
        for(int i = 0; i<n; i++) prefix[i+1] = prefix[i]+nums[i];
        deque<pair<int,int>> q;
        long long ans = 0;
        int r = n-1,l = n-1;
        long long sum = 0;
        while(l>=0) {
            while(!q.empty() && q.front().first < nums[l]) {
                auto x = q.front();
                q.pop_front();
                if(!q.empty()) {
                    sum -= 1ll*x.first*(q.front().second-x.second)-(prefix[q.front().second]-prefix[x.second]);
                }
            } 
            if(!q.empty()) sum += 1ll*nums[l]*(q.front().second-l)-(prefix[q.front().second]-prefix[l]);
            q.push_front({nums[l],l});
            while(l<r && sum+1ll*q.back().first*(r-q.back().second+1)-(prefix[r+1]-prefix[q.back().second]) > k) {
                r--;
                while(!q.empty() && q.back().second > r) {
                    auto x = q.back();
                    q.pop_back();
                    if(!q.empty()) sum -= 1ll*q.back().first*(x.second-q.back().second)-(prefix[x.second]-prefix[q.back().second]);
                }
            }
            ans += r-l+1;
            l--;
        }
        return ans;
    }
};