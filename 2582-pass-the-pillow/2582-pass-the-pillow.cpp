class Solution {
public:
    int passThePillow(int n, int t) {
        int i =1;
        bool flag = true;
        while(t--) {
            if(flag) {
                i++;
            }
            else {
                i--;
            }
            if(i == 1) {
                flag = true;
            }
            if(i == n) {
                flag = false;
            }
        }
        return i;
    }
};