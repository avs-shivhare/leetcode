class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2) return n;
        int ans = 1;
        for(int i = 0; ans<=n; i++) {
            ans <<= 1;
        }
        return ans;
    }
};