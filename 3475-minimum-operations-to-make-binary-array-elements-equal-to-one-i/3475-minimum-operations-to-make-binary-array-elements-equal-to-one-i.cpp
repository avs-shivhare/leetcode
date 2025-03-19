class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for(int i = 0; i<n; i++) {
            if(i+3 <= n && nums[i] == 0) {
                cnt++;
                for(int j = i; j<i+3; j++) {
                    nums[j] = !nums[j];
                }
            }
        }
        for(auto i: nums) {
            if(i == 0) return -1;
        }
        return cnt;
    }
};