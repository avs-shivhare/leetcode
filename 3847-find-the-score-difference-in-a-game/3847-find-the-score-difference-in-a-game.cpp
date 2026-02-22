class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int first = 0,second = 0;
        bool flag = true;
        int n = nums.size();
        for(int i = 0; i<n; i++) {
            if(nums[i]&1) flag = !flag;
            if((i+1)%6 == 0) flag = !flag;
            if(flag) first += nums[i];
            else second += nums[i];
        }
        return first-second;
    }
};