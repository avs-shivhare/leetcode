class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        int n = nums.size();
        vector<bool> vis(n,false);
        for(int i = 0; i<n; i++) {
            if(q.size() < k) {
                vis[i] = true;
                q.push({nums[i],i});
            }
            else if(q.top().first < nums[i]) {
                vis[q.top().second] = false;
                q.pop();
                vis[i] = true;
                q.push({nums[i],i});
            }
        }
        vector<int> ans;
        for(int i = 0; i<n; i++) {
            if(vis[i]) ans.push_back(nums[i]);
        }
        return ans;
    }
};