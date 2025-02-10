class Solution {
public:
    string clearDigits(string s) {
        vector<int> ind;
        int n = s.size();
        for(int i = 0; i<n; i++) {
            if('0' <= s[i] && s[i] <= '9') {
                if(ind.empty()) continue;
                s[ind.back()] = '0';
                ind.pop_back();
            }
            else {
                ind.push_back(i);
            }
        }
        string ans = "";
        for(auto i: s) {
            if('0' <= i && i<= '9') {

            }
            else ans += i;
        }
        return ans;
    }
};