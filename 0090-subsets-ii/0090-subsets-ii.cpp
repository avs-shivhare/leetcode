class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        int subset = 1<<n;
        vector<vector<int>> ans;
        set<vector<int>> cont;
        for(int i = 0; i<subset; i++) {
            vector<int> temp;
            for(int j =0; j<n; j++) {
                if(i & (1<<j)) temp.push_back(nums[j]);
            }
            sort(temp.begin(),temp.end());
            cont.insert(temp);
        }
        for(auto i: cont) {
            ans.push_back(i);
        }
        return ans;
    }
};