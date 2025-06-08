class Solution {
public:
    int countPermutations(vector<int>& nums) {
        int n = nums.size();
        bool flag = true;
        for(int i = 1; i<n; i++) {
            if(nums[0] >= nums[i]) {
                flag = false;
                break;
            } 
        }
        if(!flag) return 0;
        int mod = 1e9+7;
        long long ans = 1;
        long long ti = n-1;
        while(ti) {
            ans *= ti;
            ans %= mod;
            ti--;
        }
        return ans;
    }
};