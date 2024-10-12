class Solution {
public:
    int minGroups(vector<vector<int>>& in) {
        int cnt = 0,ans = 0;
        sort(in.begin(),in.end());
        priority_queue<int,vector<int>,greater<int>> q;
        for(auto i: in) {
            while(!q.empty() && q.top() < i[0]) q.pop();
            ans = max(ans,(int)q.size()+1);
            q.push(i[1]);
        }
        return ans;
    }
};