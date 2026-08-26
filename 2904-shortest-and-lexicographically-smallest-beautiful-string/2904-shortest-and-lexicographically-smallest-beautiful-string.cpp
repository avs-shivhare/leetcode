class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int cnt = 0;
        unordered_map<int,int> mpp;
        mpp[0] = -1;
        string ans = "";
        int n = s.size();
        for(int i = 0; i<n; i++) {
            cnt += s[i]-'0';
            int rem = cnt-k;
            if(mpp.find(rem) != mpp.end()) {
                if(ans.empty() || ans.size() > i-mpp[rem]) {
                    ans = s.substr(mpp[rem]+1,i-mpp[rem]);
                }
                else if(ans.size() == i-mpp[rem]) {
                    ans = min(ans,s.substr(mpp[rem]+1,i-mpp[rem]));
                }
            }
            mpp[cnt] = i;
        }
        return ans;
    }
};