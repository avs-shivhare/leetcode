class Solution {
public:
    string evaluate(string s, vector<vector<string>>& k) {
        unordered_map<string,string> mpp;
        for(auto &i: k) mpp[i[0]] = i[1];
        string ans = "";
        int n = s.size();
        for(int i = 0; i<n; i++) {
            if(s[i] == '(') {
                int j = i+1;
                string t = "";
                while(j<n && s[j] != ')') {
                    t += s[j];
                    j++;
                }
                if(mpp.find(t) != mpp.end()) {
                    ans += mpp[t];
                }
                else ans += "?";
                i = j;
            }
            else {
                ans += s[i];
            }
        }
        return ans;
    }
};