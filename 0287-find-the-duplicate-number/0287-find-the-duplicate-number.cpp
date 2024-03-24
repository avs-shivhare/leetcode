class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n =nums.size();
        int slow =0,fast =0;
        do{
            fast = nums[nums[fast]];
            slow = nums[slow];
            if(fast == slow) {
                fast = 0;
                while(fast != slow) {
                    fast = nums[fast];
                    slow = nums[slow];
                }
                return slow;
            }
        }
        while(fast != slow);
        return slow;
    }
};