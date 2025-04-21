class Solution {
public:
    int numberOfArrays(vector<int>& diff, int l, int r) {
        long long sum =0;
        long long maxi = 0;
        long long mini = 0;
        for(auto i: diff) {
            sum += i;
            maxi = max(maxi,sum);
            mini = min(mini,sum);
        }
        return max(0LL, r-l-maxi+mini+1);
    }
};