class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int,string,greater<int>> mpp;
        int n = names.size();
        for(int i =0; i<n; i++) {
            mpp[heights[i]] = names[i];
        } 
        vector<string> ans;
        for(auto i: mpp) {
            ans.push_back(i.second);
        }
        return ans;
    }
};