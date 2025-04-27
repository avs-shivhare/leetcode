class Solution {
public:
    string findCommonResponse(vector<vector<string>>& res) {
        unordered_map<string,int> mpp;
        for(auto i: res) {
            unordered_map<string,int> temp;
            for(auto j: i) {
                temp[j]++;
            }
            for(auto j: temp) {
                mpp[j.first]++;
            }
        }
        string ans = "";
        int cnt = 0;
        for(auto i: mpp) {
            if(cnt < i.second) {
                cnt = i.second;
                ans = i.first;
            }
            else if(cnt == i.second && ans > i.first) {
                ans = i.first;
            }
        }
        return ans;
    }
};