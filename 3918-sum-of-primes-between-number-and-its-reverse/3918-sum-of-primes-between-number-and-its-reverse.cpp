class Solution {
public:
    int prime(int l,int r) {
        vector<bool> p(r+1,true);
        int sq = sqrt(r);
        p[0] = false;
        p[1] = false;
        for(int i = 2; i<=sq; i++) {
            if(p[i]) {
                for(int j = i*i; j<=r; j+=i) {
                    p[j] = false;
                }
            }
        }
        int cnt = 0;
        for(int i = l; i<=r; i++) {
            if(p[i]) cnt += i;
        }
        return cnt;
    }
    int reverse(int n) {
        int rev = 0;
        while(n) {
            rev = rev*10+(n%10);
            n /= 10;
        }
        return rev;
    }
    int sumOfPrimesInRange(int n) {
        int r= reverse(n);
        int maxi = max(n,r);
        int mini = min(n,r);
        return prime(mini,maxi);
    }
};