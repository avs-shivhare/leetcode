class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        vector<bool> prime(33,true);
        prime[0] = false;
        prime[1] = false;
        for(int i = 2; i*i<=32; i++) {
            if(prime[i]) {
                for(int j = i*i; j<=32; j+= i) {
                    prime[j] = false;
                }
            }
        }
        int ans = 0;
        for(int i = left; i<=right; i++) {
            int cnt = 0;
            for(int j = 0; j<32; j++) {
                if(i&(1<<j)) cnt++;
            }
            if(prime[cnt]) ans++;
        }
        return ans;
    }
};