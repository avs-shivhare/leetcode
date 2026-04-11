class Solution {
public:
    int find(int n,int d) {
        int cnt = 0;
        while(n) {
            if(n%10 == d) cnt++;
            n /= 10;
        }
        return cnt;
    }
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int ans = 0;
        for(auto &i: nums) {
            ans += find(i,digit);
        }
        return ans;
    }
};