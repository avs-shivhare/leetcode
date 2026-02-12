class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int ans = 0;
        for(int i = 0; i<n; i++) {
            int maxi = 0;
            unordered_map<char,int> mpp;
            for(int j = i; j<n; j++) {
                mpp[s[j]]++;
                maxi = max(maxi,mpp[s[j]]);
                bool flag = true;
                for(auto &j: mpp) {
                    if(j.second != maxi) {
                        flag = false;
                        break;
                    }
                }
                if(flag) ans = max(ans,j-i+1);
            }
        }
        return ans;
    }
};