class Solution {
public:
    void f(int ind,int target,vector<int> &can,vector<vector<int>> &ans,vector<int> &temp) {
        if(target == 0) {
            ans.push_back(temp);
            return;
        }
        for(int i = ind; i<can.size(); i++) {
            if(i>ind && can[i] == can[i-1]) continue;
            if(can[i] >target) break;
            temp.push_back(can[i]);
            f(i+1,target-can[i],can,ans,temp);
            temp.pop_back(); 
        }
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        int n = candidates.size();
        f(0,target,candidates,ans,temp);
        //for(auto i: st) ans.push_back(i);
        return ans; 
    }
};