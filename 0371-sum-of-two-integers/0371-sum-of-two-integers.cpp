class Solution {
public:
    //using bitwise xor operator
    
    //setBit function for set/reset ith bit in ans variable
    void setBit(int &ans,int i,int bit) {
        ans = ans | (bit<<i);
    }
    int getSum(int a, int b) {
        //return a+b;
        int ans = 0;
        int c = 0;
        //loop in 32 bits, apply xor operation and carry a variable c that store carry
        for(int i =0; i<32; i++) {
            //find ith bit in integer a
            int t1 = (1<<i)& a;
            //find ith bit in integer b
            int t2 = (1<<i)&b;
            //check if carry is 1 or 0
            if(c) {
                //if t1 is 1 and c is 1
                if(t1) {
                    c =1;
                    t1 =0;
                }
                //if t1 is 1 and c is 1
                else {
                    c =0;
                    t1 =1;
                }
            }
            //if both t1 and t2 is 1
            if(t1 && t2) {
                c =1;
                setBit(ans,i,0);
            }
            //if either t1 or t1 is 1
            else if(t1 || t2) {
                setBit(ans,i,1);
            }
            //if neither t1 nor t2 is 1
            else {
                setBit(ans,i,0);
            }
        }
        return ans;
    }
};