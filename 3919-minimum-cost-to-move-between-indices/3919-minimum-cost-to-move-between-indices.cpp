class Solution {
public:
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> prefix(n,0), suffix(n,0);
        suffix[n-2] = 1;
        prefix[1] = 1;
        for(int i = 1; i<n-1; i++) {
            int prev = abs(nums[i]-nums[i-1]);
            int next = abs(nums[i]-nums[i+1]);
            if(prev > next) {
                prefix[i+1] = prefix[i]+1;
            }
            else prefix[i+1] = prefix[i]+next;
        }
        for(int i = n-2; i>0; i--) {
            int next = abs(nums[i]-nums[i-1]);
            int prev = abs(nums[i]-nums[i+1]);
            if(prev >= next) {
                suffix[i-1] = suffix[i]+1;
            }
            else suffix[i-1] = suffix[i]+next;
            //cout<<suffix[i]<<" "<<prev<<" "<<next<<endl;
        }
        // for(auto &i: suffix) cout<<i<<" ";
        // cout<<endl;
        vector<int> ans;
        for(auto &i: queries) {
            if(i[0] > i[1]) {
                int sum = suffix[i[1]];
                sum -= suffix[i[0]];
                ans.push_back(min(sum,abs(nums[i[1]]-nums[i[0]])));
            }
            else {
                int sum = prefix[i[1]];
                sum -= prefix[i[0]];
                ans.push_back(min(sum,abs(nums[i[1]]-nums[i[0]])));
            }
        }
        return ans;
    }
};