class Solution {
public:
    bool hasSpecialSubstring(string s, int k) {
        int n = s.size();
        for(int i = 0; i<n; i++) {
            unordered_map<char,int> mpp;
            for(int j = i; j<n; j++) {
                mpp[s[j]]++;
                if(j-i+1 == k && mpp.size() == 1) {
                    bool flag = true;
                    if(i > 0 && s[i-1] == s[i]) flag = false;
                    if(j +1 < n && s[j+1] == s[j]) flag = false;
                    if(flag) return true;
                }
            }
        }
        return false;
    }
};