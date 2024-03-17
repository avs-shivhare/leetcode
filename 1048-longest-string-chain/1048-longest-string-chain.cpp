class Solution {
public:
    bool comp(string &s1,string &s2) {
        return s1.size() < s2.size();
    }
    bool compare(string s1, string s2) {
        if(s1.size()  != s2.size()+1) return false;
        int n = s1.size();
        int first =0,second =0;
        while(first<n) {
            if( second < s2.size() && s1[first] == s2[second]) {
                first++;
                second++;
            }
            else first++;
        }
        if(s2.size() == second && s1.size() == first) return true;
        return false;
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),[](const string &s1,const string &s2) {
            return s1.size() < s2.size();
        });
        int n = words.size();
        vector<int> dp(n,1);
        int ans =1;
        for(int i =0; i<n; i++) {
            for(int j =0; j<i; j++) {
                if(compare(words[i],words[j]) && dp[i] < dp[j]+1) {
                    dp[i] = dp[j]+1;
                }
                
            }
            if(dp[i] > ans) {
                ans = dp[i];
            }
        }
        return ans;
    }
};