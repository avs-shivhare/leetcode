class Solution {
public:
    void f(vector<vector<int>> &ans,int nums,int &n,int &k,vector<int> &temp) {
        if(temp.size() == k) {
            ans.push_back(temp);
            return;
        }
        if(nums == n+1) {
            if(temp.size() == k) ans.push_back(temp);
            return;
        }
        temp.push_back(nums);
        f(ans,nums+1,n,k,temp);
        temp.pop_back();
        f(ans,nums+1,n,k,temp);
        return;
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
        f(ans,1,n,k,temp);
        return ans;
    }
};