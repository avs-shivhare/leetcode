class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int> mpp;
        int n = s.size();
        for(int i =0; i<n; i++) {
            if(i+10<=n) {
                string temp = s.substr(i,10);
                mpp[temp]++;
            }
        }
        vector<string> ans;
        for(auto i: mpp) {
            if(i.second > 1) ans.push_back(i.first);
        }
        return ans;
    }
};