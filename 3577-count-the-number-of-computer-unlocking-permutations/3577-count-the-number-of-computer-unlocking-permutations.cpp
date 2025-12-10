class Solution {
public:
    int countPermutations(vector<int>& arr) {
        int n = arr.size();
        for(int i = 1; i<n; i++) {
            if(arr[i] <= arr[0]) return 0;
        }
        long long ans = 1;
        int mod = 1e9+7;
        for(int i = 2; i<n; i++) {
            ans *= 1ll*i;
            ans %= mod;
        }
        return ans;
    }
};