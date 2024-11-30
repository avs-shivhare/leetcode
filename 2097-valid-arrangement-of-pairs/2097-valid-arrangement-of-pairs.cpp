class Solution {
public:
    void dfs(vector<int> &st,int node,map<int,vector<int>> &mpp) {
        while(!mpp[node].empty()) {
            auto x = mpp[node].back();
            mpp[node].pop_back();
            dfs(st,x,mpp);
        }
        st.push_back(node);
    }
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        map<int,vector<int>> mpp;
        map<int,int> out;
        for(auto i: pairs) {
            mpp[i[0]].push_back(i[1]);
            out[i[0]]++;
            out[i[1]]--;
        }
        int el = out.begin()->first;
        for(auto i: out) {
            if(i.second == 1) {
                el = i.first;
                //cout<<"done"<<endl;
                break;
            }
        }
        //cout<<el<<endl;
        vector<int> st;
        dfs(st,el,mpp);
        reverse(st.begin(),st.end());
        vector<vector<int>> ans;
        int n = st.size();
        ans.push_back({st[0],st[1]});
        for(int i =2; i<n; i++) {
            ans.push_back({st[i-1],st[i]});
        }
        return ans;
    }
};