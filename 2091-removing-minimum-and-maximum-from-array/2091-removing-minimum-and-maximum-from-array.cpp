class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int mini_id = 0;
        int maxi_id = 0;
        for(int i =0; i<n; i++) {
            if(nums[mini_id] > nums[i]) {
                mini_id = i;
            }
            if(nums[maxi_id] < nums[i]) {
                maxi_id = i;
            }
        }
        int front = max(maxi_id,mini_id)+1;
        int back = n- min(maxi_id,mini_id);
        int both = (min(maxi_id,mini_id)+1)+(n-max(mini_id,maxi_id));
        return min({front,back,both});
    }
};