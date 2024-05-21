class Solution {
public:
    // const int m  = 1e5+1;
    // int sumFourDivisors(vector<int>& nums) {
    //     vector<int> sumOfDivisors(m+1,0);
    //     vector<int> count(m+1,0);
    //     int sum = 0;
    //     // preprocess and find sum of all the divisore and count of all the divisore
    //     for(int i =1; i<m; i++) {
    //         for(int j = i; j<m; j+= i) {
    //             sumOfDivisors[j]+= i;
    //             count[j]+=1;
    //         }
    //     }
    //     for(auto i: nums) {
    //         if(count[i] == 4) {
    //             sum += sumOfDivisors[i];
    //         }
    //     }
    //     return sum;
    // }

    // 2nd approach calculate all diviors using sqrt(element of nums) , if divisore count is equal to 4 than add sum of this divisore into sum;
    int sumFourDivisors(vector<int>& nums) {
        int sum = 0;
        for(auto i: nums) {
            vector<int> temp;
            int t = 0;
            int cnt = 0;
            for(int j =1; j*j<=i; j++) {
                if(i%j == 0) {
                    if(i/j == j) {
                        cnt++;
                        t+= i;
                    }
                    else {
                        cnt +=2;
                        t += j;
                        t += i/j;
                    }
                }
                if(cnt > 4) {
                    cnt = -1;
                    break;
                }
            }
            if(cnt == 4) sum += t;
        }
        return sum;
    }
};