class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        long long pro = 1;
        long long sum = 0;
        int last = -1;
        int n = nums.size();
        for(int i = n-1; i>=0; i--) {
            long long x = 0;
            bool flag = __builtin_mul_overflow(nums[i]*1ll,pro,&x);
            if(last == -1 && flag) {
                last = i+1;
            }
            else if(last == -1 && !flag) {
                pro *= 1ll*nums[i];
            }
        }
        for(int i = 0; i<n; i++) {
            if(i >= last) pro /= 1ll*nums[i];
            if(pro == sum) return i;
            sum += nums[i];
        }
        return -1;
    }
};