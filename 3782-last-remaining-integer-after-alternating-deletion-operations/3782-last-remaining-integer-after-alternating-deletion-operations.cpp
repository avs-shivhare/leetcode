class Solution {
public:
    long long lastInteger(long long n) {
        long long first = 1,last = n;
        long long op = 0;
        long long len = n;
        bool flag = true;
        while(len > 1) {
            if((len&1ll) == 0) {
                if(flag) {
                    last = last-(1ll<<op);
                }
                else {
                    first = first+(1ll<<op);
                }
            }
            len = (len+1)>>1;
            op++;
            flag = !flag;
        }
        return first;
    }
};