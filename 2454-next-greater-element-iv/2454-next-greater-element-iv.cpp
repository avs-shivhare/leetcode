class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,-1);
        stack<pair<int,int>> st;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        for(int i =0; i<n; i++) {
            while(!q.empty() && q.top().first < nums[i]) {
                ans[q.top().second] = nums[i];
                q.pop();
            }
            while(!st.empty() && st.top().first < nums[i]) {
                q.push(st.top());
                st.pop();
            }
            st.push({nums[i],i});
        }
        return ans;
    }
};