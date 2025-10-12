class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int ans = 0;
        for(int i = 0; i<n; i++) {
            unordered_map<char,int> mpp;
            for(int j = i; j<n;j++) {
                mpp[s[j]]++;
                bool check = true;
                int mini = mpp[s[j]];
                for(auto &x : mpp) {
                    if(mini != x.second) {
                        check = false;
                        break;
                    }
                }
                if(check) ans = max(ans,j-i+1);
            }
        }
        return ans;
    }
};