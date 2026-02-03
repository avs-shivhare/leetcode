class Solution {
public:
    int find(vector<int> &arr) {
        if(arr.empty()) return 0;
        vector<int> ans;
        int n = arr.size();
        ans.push_back(arr[0]);
        for(int i = 1; i<n; i++) {
            if(ans.back() < arr[i]) ans.push_back(arr[i]);
            else {
                int ind = lower_bound(ans.begin(),ans.end(),arr[i])-ans.begin();
                ans[ind] = arr[i];
            }
        }
        return (int)ans.size();
    }
    int longestSubsequence(vector<int>& nums) {
        vector<vector<int>> bit(32);
        for(auto &i: nums) {
            for(int j = 0; j<32; j++) {
                if(i&(1<<j)) bit[j].push_back(i);
            }
        }
        int ans = 0;
        for(int i = 0; i<32; i++) {
            ans = max(ans,find(bit[i]));
        }
        return ans;
    }
};