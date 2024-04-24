class Solution {
public:
    int tribonacci(int n) {
        int ans = 0;
        if(n == 0) return ans;
        if(n == 1 || n == 2) return 1;
        int f = 0,s =1,t =1;
        int i =3;
        while(i<=n) {
            ans = f+s+t;
            f = s;
            s =t;
            t = ans;
            i++;
        }
        return ans;
    }
};