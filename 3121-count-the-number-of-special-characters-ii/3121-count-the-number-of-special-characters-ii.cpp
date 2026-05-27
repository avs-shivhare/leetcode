class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> up(26,-1),low(26,-1);
        int n = word.size();
        int cnt = 0;
        for(int i = 0; i<n; i++) {
            if('a' <= word[i] && word[i] <= 'z') {
                low[word[i]-'a'] = i;
            }
            else {
                if(up[word[i]-'A'] == -1) {
                    up[word[i]-'A'] = i;
                }
            }
        }
        for(int i = 0; i<26; i++) {
            if(low[i] < up[i] && low[i] != -1) cnt++;
        }
        return cnt;
    }
};