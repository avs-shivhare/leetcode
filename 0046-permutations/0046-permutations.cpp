class Solution {
public:
    void f(int ind,int &n, vector<int> &nums,vector<vector<int>> &ans) {
        if(ind == n) {
            ans.push_back(nums);
            return;
        }
        for(int i =ind; i<n; i++) {
            swap(nums[ind],nums[i]);
            f(ind+1,n,nums,ans);
            swap(nums[ind],nums[i]);
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        f(0,n,nums,ans);
        return ans;
    }
};