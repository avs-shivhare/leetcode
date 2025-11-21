class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        vector<int> prefix(26,0),suffix(26,0);
        unordered_map<char,set<int>> mpp;
        for(int i = 0; i<n; i++) {
            suffix[s[i]-'a']++;
        }
        int ans = 0;
        for(int i = 0; i<n; i++) {
            suffix[s[i]-'a']--;
            for(int j = 0; j<26; j++) {
                if(prefix[j] && suffix[j] && mpp[s[i]].find(j) == mpp[s[i]].end()) {
                    mpp[s[i]].insert(j);
                    ans++;
                }
            }
            prefix[s[i]-'a']++;
        }
        return ans;
    }
};