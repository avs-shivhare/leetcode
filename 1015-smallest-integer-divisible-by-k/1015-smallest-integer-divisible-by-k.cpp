class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if((k&1) == 0) return -1;
        else if(k%5 == 0) return -1;
        int ans = 0;
        int rem = 0;
        do {
            rem = rem*10+1;
            rem %= k;
            ans++;
        }
        while(rem);
        return ans;
    }
};