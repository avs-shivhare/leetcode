class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        int ans = 0;
        vector<int> temp(n,0);
        for(int i = 0; i<m; i++) {
            bool flag = true;
            bool tight = false;
            vector<int> temp2;
            for(int j = 1; j<n; j++) {
                if(temp[j] == -1) continue;
                if(strs[j-1][i] > strs[j][i]) {
                    flag = false;
                    tight = false;
                    break;
                }
                else if(strs[j-1][i] == strs[j][i]) {
                    tight = true;
                    temp[j] = 1;
                }
                else temp2.push_back(j);
            }
            if(flag && !tight) return ans;
            else if(!flag) ans++;
            else {
                for(auto x: temp2) temp[x] = -1;
            }
        }
        return ans;
    }
};