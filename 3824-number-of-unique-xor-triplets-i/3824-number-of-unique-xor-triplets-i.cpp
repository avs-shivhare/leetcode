class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
        if(n < 3) return n;
        while(n) {
            cnt++;
            n = n>>1;
        }
        return 1<<cnt;
    }
};