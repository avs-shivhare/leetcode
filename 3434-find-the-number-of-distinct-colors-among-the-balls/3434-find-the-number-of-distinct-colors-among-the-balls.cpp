class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,unordered_set<int>> mpp;
        unordered_map<int,int> mpp2;
        vector<int> ans;
        for(auto i: queries) {
            if(mpp2.count(i[0])) {
                int color = mpp2[i[0]];
                mpp[color].erase(i[0]);
                if(mpp[color].size() == 0) mpp.erase(color);
                
            }
            mpp[i[1]].insert(i[0]);
            mpp2[i[0]] = i[1];
            ans.push_back((int)mpp.size());
        }
        return ans;
    }
};