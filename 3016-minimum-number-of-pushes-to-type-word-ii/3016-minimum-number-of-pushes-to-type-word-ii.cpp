class Solution {
public:
    int minimumPushes(string word) {
        vector<int> fre(26,0);
        for(auto &i: word) {
            fre[i-'a']++;
        }
        sort(fre.begin(),fre.end(),greater<int>());
        int ans = 0;
        for(int i = 0; i<26; i++) {
            ans += fre[i]*((i+8)/8);
        }
        return ans;
    }
};