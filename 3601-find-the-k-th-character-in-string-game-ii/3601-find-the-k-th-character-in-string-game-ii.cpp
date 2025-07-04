class Solution {
public:
    char kthCharacter(long long k, vector<int>& op) {
        k--;
        long long last = 0;
        int ind = 0;
        for(int i = 63; i>=0; i--) {
            if(k&(1ll<<i)) {
                last = 1ll<<(i+1);
                ind = i;
                break;
            }
        }
        int cnt = 0;
        while(k) {
            long long temp = last>>1ll;
            if(op[ind]) {
                cnt += k/temp;
            }
            ind--;
            last = temp;
            k %= temp;
        }
        return 'a'+(cnt%26);
    }
};