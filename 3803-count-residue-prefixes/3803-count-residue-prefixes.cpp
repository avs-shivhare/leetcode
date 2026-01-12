class Solution {
public:
    int residuePrefixes(string s) {
        int n = s.size();
        int cnt = 0;
        unordered_map<char,int> mpp;
        for(int i = 0; i<n; i++) {
            mpp[s[i]]++;
            if(mpp.size() == (i+1)%3) cnt++;
        }
        return cnt;
    }
};