class Solution {
public:
    void f(int ind,int sum,int &k,int &n,vector<vector<int>> &ans,vector<int> &temp) {
        if(temp.size() == k) {
            if(sum == n) ans.push_back(temp);
            return;
        }
        if(ind == 10) return;
        if(sum+ind <= n) {
            temp.push_back(ind);
            f(ind+1,sum+ind,k,n,ans,temp);
            temp.pop_back();
        }
        f(ind+1,sum,k,n,ans,temp);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        f(1,0,k,n,ans,temp);
        return ans;
    }
};