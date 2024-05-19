class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int> mpp;
        int n = s.size();
        for(int i =0; i<n; i++) {
            mpp[t[i]]++;
        }
        int cnt = 0;
        for(int i =0; i<n; i++) {
            if(mpp.find(s[i]) != mpp.end()) {
                mpp[s[i]]--;
                if(mpp[s[i]] == 0) mpp.erase(s[i]);
            }
            else {
                cnt++;
            }
        }
        return cnt;
    }
};