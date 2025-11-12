class Solution {
public:
    int gcd(int a,int b) {
        if(a == 0) return b;
        if(b == 0) return a;
        if(a > b) return gcd(a%b,b);
        return gcd(a,b%a);
    }
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for(auto i: nums) {
            if(i == 1) cnt++;
        }
        if(cnt) return n-cnt;
        int ans = 1e9;
        for(int i = 0; i<n; i++) {
            int g = nums[i];
            for(int j = i+1; j<n; j++) {
                g = gcd(g,nums[j]);
                if(g == 1) {
                    ans = min(ans,j-i+n-1);
                    break;
                }
            }
        }
        if(ans  == 1e9) return -1;
        return ans;
    }
};