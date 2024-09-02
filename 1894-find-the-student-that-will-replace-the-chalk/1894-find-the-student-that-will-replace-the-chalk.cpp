class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum = 0;
        for(auto i: chalk) {
            sum += i;
        }
        long long x = (long long)k% sum;
        int n = chalk.size();
        for(int i = 0; i<n; i++) {
            if(chalk[i] > x) {
                return i;
            }
            else x -= chalk[i];
        }
        return -1;
    }
};