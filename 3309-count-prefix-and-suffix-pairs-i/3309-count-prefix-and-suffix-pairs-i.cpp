class Solution {
public:
    bool find(string &s1,string &s2) {
        int n = s1.size();
        int m = s2.size();
        if(n>m) return false;
        if(s2.substr(0,n)  == s1 && s2.substr(m-n) == s1) return true;
        return false;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int cnt = 0;
        int n = words.size();
        for(int i = 0; i<n; i++) {
            for(int j = i+1; j<n; j++) {
                cnt += find(words[i],words[j]);
            }
        }
        return cnt;
    }
};