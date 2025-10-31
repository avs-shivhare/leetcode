class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int,int> mpp;
        for(auto i: nums) {
            mpp[i]++;
        } 
        vector<int> ans;
        for(auto i: mpp) {
            if(i.second == 2) ans.push_back(i.first);
        }
        return ans;
    }
};