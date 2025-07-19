class Solution {
public:
    vector<bool> prime;
    void f(int n) {
        prime.resize(n+1,true);
        prime[0] = false;
        prime[1] = false;
        for(int i = 2; i*i<=n; i++) {
            if(prime[i]) {
                for(int j = i*i; j<=n; j+= i) {
                    prime[j] = false;
                }
            }
        }
    }
    long long splitArray(vector<int>& nums) {
        int n = nums.size();
        long long sum1 = 0,sum2 = 0;
        f(n);
        for(int i = 0; i<n; i++) {
            if(prime[i]) sum1 += nums[i];
            else sum2 += nums[i];
        }
        return abs(sum1-sum2);
    }
};