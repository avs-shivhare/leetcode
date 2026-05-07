class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n,0);
        prefix[0] = nums[0];
        for(int i = 1; i<n; i++) {
            prefix[i] = max(prefix[i-1],nums[i]);
        }
        priority_queue<pair<int,int>> maxi;
        vector<int> ans(n,0);
        for(int i = n-1; i>=0; i--) {
            while(!maxi.empty() && nums[maxi.top().second] >= prefix[i]) maxi.pop();
            if(!maxi.empty()) ans[i] = maxi.top().first;
            else ans[i] = prefix[i];
            maxi.push({ans[i],i});
        }
        return ans;
    }
};