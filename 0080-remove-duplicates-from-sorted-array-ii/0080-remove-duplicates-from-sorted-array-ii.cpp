class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i =0;
        int dup = 1e9,cnt = 0;
        while(i<nums.size()) {
            if(dup == nums[i] && cnt < 2) {
                cnt++;
            }
            else if(dup == nums[i]) {
                nums.erase(nums.begin()+i);
                continue;
            }
            else {
                dup = nums[i];
                cnt =1;
            }
            i++;
        }
        return nums.size();
    }
};