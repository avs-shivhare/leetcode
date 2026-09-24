class Solution {
public:
    int find(int n) {
        int cnt = 0;
        while(n) {
            cnt += n%10;
            n /= 10;
        }
        return cnt;
    }
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i<n; i++) {
            if(i == find(nums[i])) return i;
        }
        return -1;
    }
};