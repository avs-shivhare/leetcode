class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        int n = words.size();
        vector<string> ans;
        vector<int> fr(26,0);
        for(char i: pattern) {
            fr[i-'a']++;
        }
        for(int i = 0;i<n; i++) {
            vector<int> fr2(26,0);
            for(char j : words[i]) {
                fr2[j-'a']++;
            }
            bool f = true;
            for(int j = 0; j<pattern.size(); j++) {
                if(fr2[words[i][j]-'a'] != fr[pattern[j]-'a']) {
                    f = false;
                    break;
                }
                if(j>0) {
                    if((words[i][j-1] != words[i][j] && pattern[j-1] == pattern[j]) || (words[i][j-1] == words[i][j] && pattern[j-1] != pattern[j])) {
                        f = false;
                        break;
                    }
                }
            }
            if(f) ans.push_back(words[i]);
        }
        return ans;
    }
};