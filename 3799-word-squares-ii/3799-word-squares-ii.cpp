class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        set<vector<string>> st;
        int n = words.size();
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                if(i == j) continue;
                for(int k = 0; k<n; k++) {
                    if(i == k || j == k) continue;
                    for(int p = 0; p<n; p++) {
                        if(i ==p || j == p || k == p) continue;
                        if(words[i][0] == words[j][0] && words[i][3] == words[k][0] && words[p][0] == words[j][3] && words[p][3] == words[k][3]) {
                            st.insert({words[i],words[j],words[k],words[p]});
                        }
                    }
                }
            }
        }
        vector<vector<string>> ans;
        for(auto &i: st) ans.push_back(i);
        return ans;
    }
};