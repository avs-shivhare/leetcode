class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(auto &i: edges) {
            adj[i[0]].push_back(i[1]);
        }
        unordered_set<int> st;
        queue<int> q;
        st.insert(k);
        q.push(k);
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            for(auto &i: adj[node]) {
                if(st.find(i) == st.end()) {
                    q.push(i);
                    st.insert(i);
                }
            }
            //adj[node] = {};
        }
        vector<int> ans;
        bool flag = true;
        for(int i = 0; i<n; i++) {
            if(st.find(i) == st.end()) {
                for(auto &j: adj[i]) {
                    if(st.find(j) != st.end()) {
                        flag = false;
                        break;
                    }
                }
            }
            if(!flag) break;
        }
        for(int i = 0; i<n; i++) {
            if(flag) {
                if(st.find(i) == st.end()) ans.push_back(i);
            }
            else ans.push_back(i);
        }
        return ans;
    }
};