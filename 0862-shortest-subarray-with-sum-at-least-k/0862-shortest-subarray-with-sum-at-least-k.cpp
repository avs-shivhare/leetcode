class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        long long prefix[n+1];
        memset(prefix,0,sizeof(prefix));
        for(int i = 1; i<=n; i++) {
            prefix[i] = nums[i-1]+prefix[i-1];
        }
        deque<int> q;
        int ans = 1e9;
        for(int i =0; i<=n; i++) {
            while(!q.empty() && prefix[q.back()] >= prefix[i]) q.pop_back();
            q.push_back(i);
            while(!q.empty() && prefix[i]-prefix[q.front()] >= k) {
                ans = min(ans,i-q.front());
                q.pop_front();
            } 
        }
        if(ans == 1e9) return -1;
        return ans;
    }
};