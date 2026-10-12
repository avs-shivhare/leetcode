class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        vector<int> fre(32);
        for(auto &i: nums) {
            for(int j = 0; j<32; j++) {
                if(i&(1<<j)) fre[j]++;
            }
        }
        long long ans = 0,mod = 1e9+7;
        for(int i = 0; i<k; i++) {
            long long temp = 0;
            for(int j = 0; j<32; j++) {
                if(fre[j]) {
                    temp |= 1<<j;
                    fre[j]--;
                }
            }
            ans += temp*temp;
            ans %= mod;
        }
        return ans;
    }
};