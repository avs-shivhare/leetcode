class Solution {
public:
    bool checkDivisibility(int n) {
        long long x = n;
        long long sum = 0,pro = 1;
        while(n) {
            sum += n%10;
            pro *= n%10;
            n /= 10;
        }
       // cout<<sum<<" "<<pro<<endl;
        return (x%(sum+pro)) == 0;
    }
};