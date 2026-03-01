class Solution {
public:
    string mergeCharacters(string s, int k) {
        int n = s.size();
        unordered_map<char,int> mpp;
        string ans = "";
        for(int i = 0; i<n; i++) {
            if(mpp.find(s[i]) != mpp.end()) {
                int diff = ans.size()-mpp[s[i]];
                if(diff > k) {
                    mpp[s[i]] = ans.size();
                    ans += s[i];
                }
            }
            else {
                mpp[s[i]] = ans.size();
                ans += s[i];
            }
        }
        return ans;
    }
};