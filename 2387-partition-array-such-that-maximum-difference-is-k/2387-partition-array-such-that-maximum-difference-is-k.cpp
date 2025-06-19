class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int cnt = 1;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int last = 0;
        for(int i = 0; i<n; i++) {
            if(nums[i]-nums[last] > k) {
                cnt++;
                last = i;
            }
        }
        return cnt;
    }
};