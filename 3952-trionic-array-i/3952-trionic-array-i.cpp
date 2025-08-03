class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if(nums[0] >= nums[1] || nums[n-1] <= nums[n-2]) return false;
        int cnt = 0;
        unordered_set<int> st;
        for(int i = 1; i<n; i++) {
            if(nums[i] < nums[i-1]) {
                if(st.count(i-1) == 0) {
                    cnt++;
                }
                st.insert(i);
            }
            else if(nums[i] == nums[i-1]) return false;
        }
        return cnt == 1;
    }
};