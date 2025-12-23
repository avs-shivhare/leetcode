class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end(),[&](auto &a,auto &b) {
            if(a[1] == b[1]) return a[0] < b[0];
            return a[1] < b[1];
        });
        priority_queue<vector<int>> q;
        for(auto &i: events) {
            q.push({i[2],i[0],i[1]});
        }
        int ans = 0;
        for(auto &i: events) {
            while(!q.empty() && q.top()[1] <= i[1]) q.pop();
            if(!q.empty()) ans = max(ans,i[2]+q.top()[0]);
            ans = max(ans,i[2]);
        }
        return ans;
    }
};