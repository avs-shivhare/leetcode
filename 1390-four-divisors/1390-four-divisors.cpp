class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int sum = 0;
        for(auto &i: nums) {
            int cnt = 0;
            int temp = 0;
            for(int j = 1; j*j<=i; j++) {
                if(i%j == 0) {
                    cnt++;
                    temp += j;
                    if(j != i/j) {
                        cnt++;
                        temp += i/j;
                    }
                }
            }
            if(cnt == 4) sum += temp;
        }
        return sum;
    }
};