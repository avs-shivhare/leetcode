class Solution {
public:
    void dfs(int i,int j,unordered_map<int,vector<vector<int>>> &row,unordered_map<int,vector<vector<int>>> &col,set<pair<int,int>> &st) {
        st.insert({i,j});
        for(auto x : row[i]) {
            if(st.count({x[0],x[1]})) continue;
            dfs(x[0],x[1],row,col,st);
        }
        for(auto x : col[j]) {
            if(st.count({x[0],x[1]})) continue;
            dfs(x[0],x[1],row,col,st);
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        unordered_map<int,vector<vector<int>>> row,col;
        set<pair<int,int>> st;
        for(auto i: stones) {
            row[i[0]].push_back({i[0],i[1]});
            col[i[1]].push_back({i[0],i[1]});
        }
        int cnt = 0;
        for(auto i: stones) {
            if(st.count({i[0],i[1]}) == 0) {
                cnt++;
                dfs(i[0],i[1],row,col,st);
            }
        }
        return stones.size()-cnt;
    }
};