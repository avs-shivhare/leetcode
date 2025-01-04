class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        int prefix[100001][26];
        memset(prefix,0,sizeof(prefix));
        int frq[26];
        unordered_map<char,vector<int>> mpp;
        int ans = 0;
        memset(frq,0,sizeof(frq));
        for(int i =  1; i<=n; i++) {
            frq[s[i-1]-'a']++;
            for(int j = 0; j<26; j++) prefix[i][j] = frq[j];
            if(mpp.count(s[i-1])) {
                if(mpp[s[i-1]].size() == 2) mpp[s[i-1]][1] = i-1;
                else mpp[s[i-1]].push_back(i-1);
            }
            else mpp[s[i-1]].push_back(i-1);
        }
        for(auto i: mpp) {
            if(i.second.size() < 2) continue;
            int low = i.second[0];
            int high = i.second[1]+1;
            for(int j = 0; j<26; j++) {
                if((i.first-'a') == j) {
                    if(prefix[high][j]-prefix[low][j] > 2) ans++;
                }
                else if(prefix[high][j]-prefix[low][j] > 0) ans++;
            }
        }
        return ans;
    }
};