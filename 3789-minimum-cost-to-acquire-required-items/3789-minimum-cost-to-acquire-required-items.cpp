class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long both = max(need1,need2)*1ll*costBoth;
        long long s1 = 1ll*cost1*need1;
        long long s2 = 1ll*cost2*need2;
        long long mini = min(need1,need2)*1ll*costBoth;
        if(need1 < need2) mini += 1ll*(need2-need1)*cost2;
        else mini += 1ll*(need1-need2)*cost1;
        return min({both,s1+s2,mini});
    }
};