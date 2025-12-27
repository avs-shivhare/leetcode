class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> meet(n,0);
        sort(meetings.begin(),meetings.end());
        set<int> st;
        for(int i = 0; i<n; i++) st.insert(i);
        priority_queue<vector<long long>,vector<vector<long long>>,greater<vector<long long>>> q;
        long long last = 0;
        for(auto i: meetings) {
            last = max(last,1ll*i[0]);
            while(!q.empty() && q.top()[0] <= last) {
                st.insert(q.top()[1]);
                q.pop();
            }
            if(st.empty()) {
                long long el = q.top()[0];
                long long ind = q.top()[1];
                q.pop();
                st.insert(ind);
                last = max(last,el);
            }
            while(!q.empty() && q.top()[0] <= last) {
                st.insert(q.top()[1]);
                q.pop();
            }
            int ind = *st.begin();
            st.erase(ind);
            meet[ind]++;
            q.push({last+i[1]-i[0],ind});
        }
        int ans = 0;
        for(int i = 0; i<n; i++) {
            //cout<<meet[i]<<" ";
            if(meet[ans] < meet[i]) ans = i;
        }
        return ans;
    }
};