class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        priority_queue<int> q;
        priority_queue<int,vector<int>,greater<int>> qq;
        sort(queries.begin(),queries.end());
        int j = 0;
        int n = nums.size();
        int cnt = 0;
        for(int i = 0; i<n; i++) {
            while(!qq.empty() && qq.top() < i) qq.pop();
            while(j<queries.size() && queries[j][0] <= i) {
                q.push(queries[j][1]);
                j++;
            }
            while(!q.empty() && qq.size() < nums[i] && q.top() >= i) {
                qq.push(q.top());
                q.pop();
                cnt++;
            }
            if(qq.size() < nums[i]) return -1;
        }
        return queries.size()-cnt;
    }
};