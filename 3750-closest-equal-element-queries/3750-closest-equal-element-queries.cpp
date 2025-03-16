class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int,vector<int>> mpp;
        int n = nums.size();
        for(int i = 0; i<n; i++) {
            mpp[nums[i]].push_back(i);
        }
        int m = queries.size();
        vector<int> ans(m,0);
        int cnt = 0;
        for(auto i: queries) {
            if(mpp[nums[i]].size() == 1) {
                ans[cnt] = -1;
                cnt++;
            }
            else {
                int diff = 1e9;
                //auto x = ;
                int ind = lower_bound(mpp[nums[i]].begin(),mpp[nums[i]].end(),i)-mpp[nums[i]].begin();
                int xn = mpp[nums[i]].size();
                if(ind -1 >= 0) diff = min(diff,mpp[nums[i]][ind]-mpp[nums[i]][ind-1]);
                if(ind +1 < xn) diff = min(diff,mpp[nums[i]][ind+1]-mpp[nums[i]][ind]);
                if(mpp[nums[i]][ind] != mpp[nums[i]][0]) diff = min({diff,mpp[nums[i]][ind]-mpp[nums[i]][0],(n+mpp[nums[i]][0])-mpp[nums[i]][ind]});
                if(mpp[nums[i]][ind] != mpp[nums[i]][xn-1]) diff = min({diff,mpp[nums[i]][xn-1]-mpp[nums[i]][ind],n+mpp[nums[i]][ind]-mpp[nums[i]][xn-1]});
                ans[cnt] = diff;
                cnt++;
            }
        }
        return ans;
    }
};