class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        long long sum = accumulate(nums.begin(),nums.end(),0ll);
        long long sum2 = 0;
        int n = nums.size();
        for(int i = 0; i<n; i++) {
            sum2 += nums[i];
            if(i+1<n && nums[i] > nums[i+1]) {
                break;
            }
            sum -= nums[i];
        }
        if(sum == sum2) return -1;
        else if(sum > sum2) return 1;
        return 0;
    }
};