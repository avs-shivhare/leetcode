class Solution {
public:
    long long minEnd(int n, int x) {
        vector<int> pos;
        for(int i =0; i<64; i++) {
            if(((long long)x & ((long long)1<<i)) == 0) pos.push_back(i);
        }
        long long ans = x;
        int i =0;
        n--;
        while(i<pos.size() && n) {
            if((n & 1) == 0) {
                i++;
            }
            else {
                ans |= (long long)1<<pos[i];
                i++;
            }
            n >>=1;
        }
        return ans;
    }
};