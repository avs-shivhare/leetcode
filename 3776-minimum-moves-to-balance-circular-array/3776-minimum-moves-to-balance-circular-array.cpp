class Solution {
public:
    long long minMoves(vector<int>& b) {
        int n = b.size();
        long long total = 0;
        int ind = -1;
        for(int i = 0; i<n; i++) {
            total += max(b[i],0);
            if(b[i] < 0) ind = i;
        }
        if(ind == -1) return 0;
        else if(total < abs(b[ind])) return -1;
        int l = (ind-1+n)%n,r = ind+1;
        long long ans = 0;
        while(l>=0 && r<2*n && b[ind] < 0) {
            int need = min(b[l]+b[r%n],abs(b[ind]));
            b[ind] += need;
            ans += 1ll*min(abs(ind-r),abs(ind-l))*need;
            l = (l-1+n)%n;
            r++;
        }
        return ans;
    }
};