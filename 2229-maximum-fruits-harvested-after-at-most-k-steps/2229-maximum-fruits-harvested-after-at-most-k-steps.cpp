class Solution {
public:
    int find(vector<vector<int>> &arr,int l,int r,int s) {
        return min((abs(s-arr[l][0])+abs(arr[l][0]-arr[r][0])),(abs(s-arr[r][0])+abs(arr[r][0]-arr[l][0])));
    }
    int maxTotalFruits(vector<vector<int>>& fruits, int s, int k) {
        int ans = 0;
        int l = 0,r = 0;
        int n = fruits.size();
        int sum = 0;
        while(r<n) {
            sum += fruits[r][1];
            while(l<r && find(fruits,l,r,s) > k) {
                sum -= fruits[l][1];
                l++;
            }
            if(find(fruits,l,r,s) <= k) {
                ans = max(ans,sum);
            }
            r++;
        }
        return ans;
    }
};