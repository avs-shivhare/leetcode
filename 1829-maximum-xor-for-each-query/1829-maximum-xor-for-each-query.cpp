class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int m) {
        vector<int> ans;
        int cnt[32];
        memset(cnt,0,sizeof(cnt));
        for(auto i: nums) {
            for(int j =0; j<32; j++) {
                if(i & (1<<j)) cnt[j]++;
            }
            int temp = 0;
            for(int j =0; j<32; j++) {
                if((cnt[j] & 1) == 0) {
                    if(j<m) temp |= 1<<j;
                }
            }
            ans.push_back(temp);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};