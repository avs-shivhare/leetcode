class Solution {
public:
    int minAllOneMultiple(int k) {
        if(!(k&1) || k%5 == 0) {
            return -1;
        }
        int rem = 1;
        int len = 1;
        while(rem%k != 0) {
            len++;
            rem = rem*10+1;
            rem %= k;
        }
        return len;
    }
};