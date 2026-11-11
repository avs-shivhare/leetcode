class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long t1 = 1ll*cost1*need1;
        long long t2 = 1ll*cost2*need2;
        long long t3 = 1ll*costBoth*max(need1,need2);
        long long ans = min(t3,t1+t2);
        if(need1 <= need2) ans = min(ans,1ll*costBoth*need1+1ll*(need2-need1)*cost2);
        else ans = min(ans,1ll*costBoth*need2+1ll*(need1-need2)*cost1);
        return ans;
    }
};