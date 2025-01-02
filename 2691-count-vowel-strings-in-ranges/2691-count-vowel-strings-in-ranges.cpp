class Solution {
public:
    bool check(char c) {
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
        return false;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> ans;
        int n = words.size();
        int prefix[n+1];
        memset(prefix,0,sizeof(prefix));
        for(int i = 1; i<=n; i++) {
            prefix[i] = prefix[i-1]+ (check(words[i-1].front()) && check(words[i-1].back()));
        }
        for(auto i: queries) {
            ans.push_back(prefix[i[1]+1]-prefix[i[0]]);
        }
        return ans;
    }
};