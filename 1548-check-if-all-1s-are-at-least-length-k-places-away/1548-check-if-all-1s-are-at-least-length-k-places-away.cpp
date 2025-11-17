class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int last = -1;
        int cnt = 0;
        int n = nums.size();
        for(int i = 0; i<n; i++) {
            if(nums[i]) {
                if(last != -1 && cnt < k) return false;
                last = i;
                cnt = 0; 
            }
            else cnt++;
        }
        return true;
    }
};