class Solution {
public:
    const int m  = 1e5+1;
    int sumFourDivisors(vector<int>& nums) {
        vector<int> sumOfDivisors(m+1,0);
        vector<int> count(m+1,0);
        int sum = 0;
        // preprocess and find sum of all the divisore and count of all the divisore
        for(int i =1; i<m; i++) {
            for(int j = i; j<m; j+= i) {
                sumOfDivisors[j]+= i;
                count[j]+=1;
            }
        }
        for(auto i: nums) {
            if(count[i] == 4) {
                sum += sumOfDivisors[i];
            }
        }
        return sum;
    }
};