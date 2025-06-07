class Solution {
public:
    string clearStars(string s) {
        map<char,vector<int>> mpp;
        int n = s.size();
        for(int i = 0; i<n; i++) {
            if(s[i] == '*') {
                char x = mpp.begin()->first;
                s[mpp[x].back()] = '1';
                mpp[x].pop_back();
                if(mpp[x].empty()) mpp.erase(x);
                s[i] = '1';
            }
            else {
                mpp[s[i]].push_back(i);
            }
        }
        string ans = "";
        for(auto i: s) {
            if(i != '1') ans += i;
        }
        return ans;
    }
};