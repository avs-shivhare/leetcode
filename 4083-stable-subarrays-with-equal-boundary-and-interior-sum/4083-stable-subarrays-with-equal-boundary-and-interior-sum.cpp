class Solution {
public:
    long long countStableSubarrays(vector<int>& arr) {
        long long ans = 0;
        long long sum = 0;
        map<long long,map<long long,long long>> mpp;
        int n = arr.size();
        int l = -2;
        long long sum2 = 0;
        for(int i = 0; i<n; i++) {
            if(l >= 0) {
                sum2 += arr[l];
                mpp[sum2][arr[l]]++;
            } 
            l++;
            long long rem = sum-arr[i];
            if(mpp.find(rem) != mpp.end() && mpp[rem].find(arr[i]) != mpp[rem].end()) {
                ans += mpp[rem][arr[i]];
            }
            sum += arr[i];
        }
        return ans;
    }
};