class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
        unordered_map<int,int> mpp;
        int ans = 0;
        for(int i : arr) {
            mpp[i] = mpp[i-diff]+1;
            ans = max(ans,mpp[i]);
        }
        return ans;
    }
};