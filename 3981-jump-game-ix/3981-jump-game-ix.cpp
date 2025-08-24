class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n,0),suffix(n,0);
        prefix[0] = nums[0];
        suffix[n-1] = nums[n-1];
        for(int i = n-2; i>=0; i--) {
            suffix[i] = min(suffix[i+1],nums[i]);
        }
        for(int i = 1; i<n; i++) {
            prefix[i] = max(prefix[i-1],nums[i]);
        }
        // for(auto i: prefix) cout<<i<<" ";
        // cout<<endl;
        // for(auto i: suffix) cout<<i<<" ";
        // cout<<endl;
        vector<int> ans(n,0);
        ans[n-1] = prefix[n-1];
        for(int i = n-2; i>= 0; i--) {
            ans[i] = prefix[i];
            if(prefix[i] > suffix[i+1]) {
                //cout<<i<<endl;
                ans[i] = ans[i+1];
            }
        }
        return ans;
    }
};