class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        long long odd = 0,even = 1;
        long long sum = 0;
        long long ans = 0;
        int mod = 1e9+7;
        for(auto &i: arr) {
            sum += i;
            if(sum&1) {
                ans += even;
                odd++;
            }
            else {
                ans += odd;
                even++;
            }
            ans %= mod;
            even %= mod;
            odd %= mod;
            sum %= 2;
        }
        return ans;
    }
};