class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans = "";
        for(int i = 0; i<num; i++) {
            if(sum) {
                int mini = min(sum,9);
                sum -= mini;
                ans += mini+'0';
            }
            else {
                ans += '0';
            }
        }
        if(sum) return "";
        return ans;
    }
};