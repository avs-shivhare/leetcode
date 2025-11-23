class Solution {
public:
    long long find(long long n) {
        long long sum = 1ll*n*(1ll*n+1)>>1;
        return sum;
    }
    vector<int> lexSmallestNegatedPerm(int n, long long target) {
        if(find(n) < llabs(target)) return {};
        vector<int> ans(n,0);
        iota(ans.begin(),ans.end(),1);
        for(int i = n; i>=1; i--) {
            if(find(i-1)-i >= target) {
                ans[i-1] *= -1;
                target += i;
            }
            else {
                target -= i;
            }
        }
        if(target == 0) {
            sort(ans.begin(),ans.end());
            return ans;
        }
        return {};
    }
};