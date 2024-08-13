class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    void find(int i,vector<int> &nums,int target) {
        if(target == 0) {
            //cout<<"done"<<endl;
            ans.push_back(temp);
            return;
        }
        for(int ind = i; ind<nums.size(); ind++) {
            if(ind > i && nums[ind-1] == nums[ind]) continue;
            if(nums[ind] > target) break;
            temp.push_back(nums[ind]);
            find(ind+1,nums,target-nums[ind]);
            temp.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& cand, int target) {
        sort(cand.begin(),cand.end());
        find(0,cand,target);
        return ans;
    }
};