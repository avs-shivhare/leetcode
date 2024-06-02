class Solution {
public:
    string clearStars(string s) {
        vector<int> mpp[26];
        int n = s.size();
        int i = 0;
        while(i<s.size()) {
            if(s[i] == '*') {
                int j = 0;
                for(j =0; j<26; j++) {
                    if(mpp[j].size() > 0) {
                        break;
                    }
                }
                s[mpp[j].back()] = '1';
                mpp[j].pop_back();
                s[i] = '1';
            }else {
                mpp[s[i]-'a'].push_back(i);
            }
            i++;
        }
        string ans = "";
        for(int i =0; i<n; i++) {
            if(s[i] != '1') {
                ans += s[i];
            }
        }
        
        return ans;
        
    }
};