class Solution {
public:
    int find(vector<int> &ls,vector<int> &ld,vector<int> &ws,vector<int> &wd) {
        int ans = 1e9;
        priority_queue<int,vector<int>,greater<int>> less;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> more;
        vector<int> temp;
        int n = ls.size();
        for(int i = 0; i<n; i++) {
            more.push({ls[i]+ld[i],i});
        }
        n = ws.size(); 
        for(int i = 0; i<n; i++) {
            temp.push_back(ws[i]+wd[i]);
        }
        sort(temp.begin(),temp.end());
        for(int i = 0; i<n; i++) {
            while(!more.empty() && ls[more.top().second] <= temp[i]) {
                less.push(ld[more.top().second]);
                more.pop();
            }
            if(!less.empty()) ans = min(ans,temp[i]+less.top());
            if(!more.empty()) ans = min(ans,more.top().first);
        }
        return ans;
    }
    int earliestFinishTime(vector<int>& ls, vector<int>& ld, vector<int>& ws, vector<int>& wd) {
        return min(find(ls,ld,ws,wd),find(ws,wd,ls,ld));
    }
};