class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        for(int i = 0; i<n; i++) {
            nums.push_back(nums[i]);
        }
        vector<int> prefix(2*n,-1), suffix(2*n,-1);
        unordered_map<int,int> mpp;
        for(int i = 2*n-1; i>=0; i--) {
            if(mpp.find(nums[i]) != mpp.end()) {
                prefix[i] = mpp[nums[i]];
                mpp[nums[i]] = min(i,mpp[nums[i]]);
            }
            else {
                mpp[nums[i]] = i;
            }
        }
        mpp.clear();
        for(int i = 0; i<2*n; i++) {
            if(mpp.find(nums[i]) != mpp.end()) {
                suffix[i] = mpp[nums[i]];
                mpp[nums[i]] = max(mpp[nums[i]],i);
            }
            else {
                mpp[nums[i]] = i;
            }
        }
        int m = queries.size();
        vector<int> ans(m,-1);
        for(int i = 0; i<m; i++) {
            int ind = prefix[queries[i]];
            int next = 1e9,prev = 1e9;
            if(ind != -1 && ind - queries[i] < n) next = ind-queries[i];
            ind = suffix[queries[i]+n];
            if(ind != -1 && queries[i] < ind) prev = queries[i]+n-ind;
            int mini = min(prev,next);
            //cout<<queries[i]<<" "<<prev<<" "<<next<<" "<<ind<<endl;
            if(mini != 1e9) ans[i] = mini;
        }
        return ans;
    }
};