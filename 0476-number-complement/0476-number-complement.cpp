class Solution {
public:
    int findComplement(int num) {
        //int ans = 0;
        int ans = 0;
        for(int i =0; i<32; i++) {
            if(num & (1<<i)) {
                ans = i;
            }
        }
        for(int i =0; i<=ans; i++) {
            if(num & (1<<i)) {
                num = num & ~(1<<i);
            }
            else {
                num = num | (1<<i);
            }
        }
        return num;
    }
};