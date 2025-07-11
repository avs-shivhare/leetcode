class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> cnt(n,0);
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> q;
        set<int> st;
        for(int i = 0; i<n; i++) st.insert(i);
        sort(meetings.begin(),meetings.end());
        for(auto i: meetings) {
            while(!q.empty() && i[0] >= q.top().first) {
                st.insert(q.top().second);
                q.pop();
            }
            if(!st.empty()) {
                int x = *st.begin();
                st.erase(x);
                q.push({i[1],x});
                cnt[x]++;
            }
            else {
                if(q.empty()) return -1;
                auto x = q.top();
                q.pop();
                long long diff = x.first-i[0];
                cnt[x.second]++;
                q.push({(long long)i[1]+diff,x.second});
            }
        }
        int c = 0,ans = 0;
        for(int i = 0; i<n; i++) {
            if(c < cnt[i]) {
                c = cnt[i];
                ans = i;
            }
        }
        return ans;
    }
};