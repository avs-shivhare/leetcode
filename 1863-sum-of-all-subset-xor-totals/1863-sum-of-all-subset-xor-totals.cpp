class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int i =0; i<(1<<n); i++) {
            int Xor = 0;
            for(int j =0; j<n; j++) {
                if((1<<j)&i) Xor ^= nums[j];
            }
            sum += Xor;
        }
        return sum;
    }
};