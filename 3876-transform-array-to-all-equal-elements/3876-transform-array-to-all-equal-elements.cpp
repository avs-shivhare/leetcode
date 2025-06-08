class Solution {
public:
    bool canMakeEqual(vector<int>& nums, int k) {
        int cnt = 0;
        int cnt2 = 0;
        vector<int> temp = nums;
        int n = nums.size();
        for(int i = 1; i<n; i++) {
            if(nums[i-1] == 1) {
                nums[i-1] *= -1;
                nums[i] *= -1;
                cnt++;
            }
            if(temp[i-1] == -1) {
                temp[i-1] *= -1;
                temp[i] *= -1;
                cnt2++;
            }
        }
        if(cnt <= k || cnt2 <= k) {
            bool flag = true;
            bool flag2 = true;
            for(int i = 0; i<n; i++) {
                //cout<<nums[i]<<" ";
                if(nums[i] != -1) {
                    flag = false;
                }
                if(temp[i] != 1) {
                    flag2 = false;
                }
            }
            if((cnt <= k && flag) || (cnt2 <= k && flag2)) return true;
        }
        return false;
    }
};