class Solution {
public:
    long long dp[101][101][101];
    long long find(int i,int j,int k,vector<int> &nums1,vector<int> &nums2) {
        if(k < 0) return -1e18;
        if(i == nums1.size() || j == nums2.size()) {
            if(k == 0) return 0;
            return -1e18;
        }
        return dp[i][j][k];
    }
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        memset(dp,0,sizeof(dp));
        int n = nums1.size();
        int m = nums2.size();
        for(int i = n-1; i>=0; i--) {
            for(int j = m-1; j>=0; j--) {
                for(int x = 0; x<=k; x++) {
                    long long take = -1e18,notTake = -1e18;
                    take = 1ll*nums1[i]*nums2[j]+find(i+1,j+1,x-1,nums1,nums2);
                    notTake = max(find(i+1,j,x,nums1,nums2),find(i,j+1,x,nums1,nums2));
                    dp[i][j][x] = max(take,notTake);
                }
            }
        }
        return find(0,0,k,nums1,nums2);
    }
};