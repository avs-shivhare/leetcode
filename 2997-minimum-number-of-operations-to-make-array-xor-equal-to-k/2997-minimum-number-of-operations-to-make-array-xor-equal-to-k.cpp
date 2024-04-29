class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int x = 0;
        for(int i: nums) {
            x ^= i;
        }
        if(x == k) return 0;
        int cnt = 0;
        for(int i =0;i<32; i++) {
            int xlsb = (x>>i) & 1;
            int klsb = (k>>i) & 1;
            if(xlsb != klsb) cnt++;
        }
        return cnt;
    }
};