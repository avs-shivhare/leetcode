class Solution {
public:
    void f(int i,vector<int> &nums,vector<vector<int>> &ans,vector<int> temp) {
        if(i == nums.size()) return;
        temp.push_back(nums[i]);
        ans.push_back(temp);
        f(i+1,nums,ans,temp);
        temp.pop_back();
        f(i+1,nums,ans,temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        ans.push_back({});
        f(0,nums,ans,{});
        return ans;
    }
};