class Solution {
public:
    vector<vector<long long>> dp;
    int find(int i,int j,vector<int> &nums1,vector<int> &nums2) {
        if(i == nums1.size() || j == nums2.size()) {
            return -1e9;
        }
        if(dp[i][j] != LLONG_MIN) return dp[i][j];
        int ans = nums1[i]*nums2[j]+max(0,find(i+1,j+1,nums1,nums2));
        ans = max({ans,find(i+1,j,nums1,nums2),find(i,j+1,nums1,nums2)});
        return dp[i][j] = ans;
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        dp.resize(n,vector<long long>(m,LLONG_MIN));
        return find(0,0,nums1,nums2);  
    }
};