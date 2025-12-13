class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& b, vector<bool>& is) {
        map<string,vector<string>> mpp; 
        mpp["electronics"] = {};
        mpp["grocery"] = {};
        mpp["pharmacy"] = {};
        mpp["restaurant"] = {};
        int n = code.size();
        for(int i = 0; i<n; i++) {
            bool flag = true;
            if(code[i].empty()) continue;
            for(auto j: code[i]) {
                char s = tolower(j);
                if(('a' <= s && s <= 'z') || ('0' <= s && s <= '9') || (s == '_')) {

                }
                else {
                    flag = false;
                    break;
                }
            }
            if(flag && mpp.find(b[i]) != mpp.end() && is[i]) mpp[b[i]].push_back(code[i]);
        }
        vector<string> ans;
        for(auto &i: mpp) {
            sort(i.second.begin(),i.second.end());
            for(auto &j: i.second) {
                ans.push_back(j);
            }
        }
        return ans;
    }
};