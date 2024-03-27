class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int cnt = 0;
        int n = nums.size();
        for(int i =0; i<n; i++) {
            long long sum = 1;
            for(int j =i; j<n; j++) {
                sum*=nums[j];
                if(sum < k) cnt++;
                else break;
            }
        }
        return cnt;
    }
};