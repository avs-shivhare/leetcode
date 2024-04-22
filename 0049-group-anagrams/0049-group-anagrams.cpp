class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mpp;
        for(string i: strs) {
            string temp = i;
            sort(temp.begin(),temp.end());
            mpp[temp].push_back(i);
        }
        vector<vector<string>> ans;
        for(auto i:mpp) {
            ans.push_back(i.second);
        }
        return ans;
    }
};