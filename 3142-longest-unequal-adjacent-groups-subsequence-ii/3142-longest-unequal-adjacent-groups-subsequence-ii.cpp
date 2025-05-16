class Solution {
public:
    bool check(string &a,string &b) {
        if(a.size() != b.size()) return false;
        int cnt = 0;
        int n = a.size();
        for(int i = 0; i<n; i++) {
            if(a[i] != b[i]) cnt++;
        }
        return cnt == 1;
    }
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<int> dp(n,1),index(n,-1);
        int last = 0;
        for(int i = 0; i<n; i++) {
            int maxi = 0;
            int ind = -1;
            for(int j = 0; j<i; j++) {
                if(groups[i] != groups[j] && check(words[i],words[j]) && maxi < dp[j]) {
                    maxi = dp[j];
                    ind = j;
                }
            }
            dp[i] += maxi;
            index[i] = ind;
            if(dp[i] > dp[last]) {
                last = i;
            }
        }
        vector<string> ans;
        while(last != -1) {
            ans.push_back(words[last]);
            last = index[last];
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};