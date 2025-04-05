class Solution {
public:
    int ans = 0;
    void find(int i,int sum,vector<int> &nums) {
        if(i == nums.size()) {
            ans += sum;
            return;
        }
        find(i+1,sum^nums[i],nums);
        find(i+1,sum,nums);
    }
    int subsetXORSum(vector<int>& nums) {
        find(0,0,nums);
        return ans;
    }
};