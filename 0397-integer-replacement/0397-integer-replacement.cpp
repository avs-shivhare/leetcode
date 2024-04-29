class Solution {
public:
    int f(long long n,unordered_map<long long,long long> &mpp) {
        if(n<=0) return 1e9;
        if(n == 1) return 0;
        if(mpp.find(n) != mpp.end()) return mpp[n];
        int mini = 1e9;
        if(n%2 == 0) {
            mini = min(mini,f(n/2,mpp));
        }
        else {
            mini = min(mini,f(n+1,mpp));
            mini = min(mini,f(n-1,mpp));
        }
        return mpp[n] = mini+1;
    }
    int integerReplacement(int n) {
        unordered_map<long long,long long> mpp;
        return f(n,mpp);
    }
};