class Solution {
public:
    int longestBalanced(string s) {
        unordered_map<int,vector<int>> mpp;
        int n = s.size();
        int zero = 0,one = 0;
        int ans = 0;
        for(int i = 0; i<n; i++) {
            if(s[i] == '0') zero++;
            else one++;
        }
        int ans2 = 2*min(zero,one);
        mpp[0].push_back(-1);
        int sum = 0;
        for(int i = 0; i<n; i++) {
            if(s[i] == '0') {
                sum--;
            }
            else {
                sum++;
            }
            if(mpp.find(sum) != mpp.end()) ans = max(ans,i-mpp[sum][0]);
            if(mpp.find(sum-2) != mpp.end()) {
                for(auto &j: mpp[sum-2]) {
                    int l = i-j;
                    int z = (l-2)>>1;
                    if(zero > z) {
                        ans = max(ans,l);
                        break;
                    }
                }
            }
            if(mpp.find(sum+2) != mpp.end()) {
                for(auto &j: mpp[sum+2]) {
                    int l = i-j;
                    int o = (l-2)>>1;
                    if(one > o) {
                        ans = max(ans,l);
                        break;
                    }
                }
            }
            mpp[sum].push_back(i);
        }
        return min(ans2,ans);
    }
};