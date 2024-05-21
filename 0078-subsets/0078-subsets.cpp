class Solution {
public:
    // // 1st approach
    // // subset by recursion or PowerSet methd
    // void findSubSet(int ind,vector<vector<int>> &ans,vector<int> &temp,vector<int> &nums,int &n) {
    //     if(ind == n) {
    //         ans.push_back(temp);
    //         return;
    //     }
    //     //include
    //     temp.push_back(nums[ind]);
    //     findSubSet(ind+1,ans,temp,nums,n);
    //     temp.pop_back();
    //     //exclude
    //     findSubSet(ind+1,ans,temp,nums,n);
    //     return;
    // }
    // vector<vector<int>> subsets(vector<int>& nums) {
    //     vector<int> temp;
    //     vector<vector<int>> ans;
    //     int n = nums.size();
    //     findSubSet(0,ans,temp,nums,n);
    //     return ans;
    // }


    // 2nd approach
    // using subset method 
    // here i use bit manipulation method to find all the subset for give array
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        for(int i =0; i<(1<<n); i++) {
            vector<int> temp;
            for(int j = 0; j<n; j++) {
                if(i&(1<<j)) temp.push_back(nums[j]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};