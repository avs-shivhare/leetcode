class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& group) {
        int n = group.size();
        unordered_map<int,vector<vector<int>>> mpp;
        for(int i =0; i<n; i++) {
            if(mpp[group[i]].empty() || mpp[group[i]].back().size()%group[i] == 0) {
                mpp[group[i]].push_back({i});
            }
            else {
                mpp[group[i]].back().push_back(i);
            }
        }
        vector<vector<int>> ans;
        for(auto i: mpp) {
            for(auto x: i.second) {
                ans.push_back(x);
            }
        }
        return ans;
    }
};