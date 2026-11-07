class Solution {
public:
    vector<int> assignTasks(vector<int>& s, vector<int>& t) {
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> q;
        set<pair<int,int>> st;
        int m = s.size();
        for(int i = 0; i<m; i++) {
            st.insert({s[i],i});
        }
        vector<int> ans;
        long long last = 0;
        int n = t.size();
        for(int j = 0; j<n; j++) {
            last = max(j*1ll,last);
            while(!q.empty() && last >= q.top().first) {
                st.insert({s[q.top().second],q.top().second});
                q.pop();
            }
            if(st.empty()) {
                last = q.top().first;
                st.insert({s[q.top().second],q.top().second});
                q.pop();
            }
            while(!q.empty() && last >= q.top().first) {
                st.insert({s[q.top().second],q.top().second});
                q.pop();
            }
            auto x = *st.begin();
            ans.push_back(x.second);
            q.push({last+t[j],x.second});
            st.erase(x);
        }
        return ans;
    }
};