class Solution {
public:
    bool check(long long mid,vector<int> &arr,vector<long long> &prefix) {
        int n = arr.size();
        for(int i = 0; i<n; i++) {
            if(mid+prefix[i] < arr[i]) return false;
            mid -= arr[i];
            if(mid < 0) mid = 0;
        }
        return true;
    }
    long long minInitialStrength(vector<int>& arr, vector<vector<int>>& boosts) {
        long long l = 0,r = 1e15;
        long long ans = 0;
        int n = arr.size();
        vector<long long> prefix(n+1,0);
        for(auto &i: boosts) {
            prefix[i[0]] += i[2];
            prefix[i[1]+1] -= i[2];
        }
        for(int i = 1; i<n; i++) prefix[i] += prefix[i-1];
        while(l<=r) {
            long long mid = (l+r)>>1ll;
            if(check(mid,arr,prefix)) {
                ans = mid;
                r = mid-1;
            }
            else l = mid+1;
        }
        return ans;
    }
};