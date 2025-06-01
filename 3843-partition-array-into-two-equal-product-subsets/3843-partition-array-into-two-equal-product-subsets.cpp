class Solution {
public:
    bool find(int i,vector<int> &nums,long long p1,long long p2,long long &target) {
        if(p1 > target || p2 > target) return false;
        if(i == nums.size()) {
            if(p1 == target && p2 == target) return true;
            return false;
        }
        return find(i+1,nums,p1*(long long)nums[i],p2,target) || find(i+1,nums,p1,p2*(long long)nums[i],target);
    }
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        return find(0,nums,1,1,target);
    }
};