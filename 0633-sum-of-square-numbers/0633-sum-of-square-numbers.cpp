class Solution {
public:
    bool judgeSquareSum(int c) {
        long long cc = ceil(sqrt(c));
        long long s = 0;
        while(s<= cc) {
            long long sum = s*s+cc*cc;
            if(sum == c) return true;
            else if(sum > c) cc--;
            else s++;
        }
        return false;
    }
};