class Solution {
public:
    void f(int ind,int &n,vector<int> &nums,set<vector<int>> &ans) {
        if(n == ind) {
            ans.insert(nums);
            return;
        }
        for(int i = ind; i<n; i++) {
            if(i>ind && nums[i] == nums[i-1]) continue;
            swap(nums[ind],nums[i]);
            f(ind+1,n,nums,ans);
            swap(nums[ind],nums[i]); 
        }
        return;
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> st;
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        f(0,n,nums,st);
        for(auto i: st) ans.push_back(i);
        return ans;
    }
};