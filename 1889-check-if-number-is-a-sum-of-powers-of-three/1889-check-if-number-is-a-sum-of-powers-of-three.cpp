class Solution {
public:
    bool find(int i,long long sum,int &n) {
        if(sum == n) return true;
        if(i == 17) return false;
        long long temp = pow(3,i);
        if(temp +sum <= n) {
            if(find(i+1,sum+temp,n)) return true;
        }
        if(find(i+1,sum,n)) return true;
        return false;
    }
    bool checkPowersOfThree(int n) {
        return find(0,0,n);
    }
};