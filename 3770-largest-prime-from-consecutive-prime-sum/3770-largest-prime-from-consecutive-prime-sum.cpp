class Solution {
public:
    void find(vector<bool> &prime,int n) {
        for(int i = 2; i*i<=n; i++) {
            if(prime[i]) {
                for(int j = i*i; j<=n; j+=i) {
                    prime[j] = false;
                }
            }
        }
        return;
    }
    int largestPrime(int n) {
        if(n <= 1) return 0;
        vector<bool> prime(n+1,true);
        find(prime,n);
        int largest = 2;
        vector<int> ans;
        for(int i = 2; i<=n; i++) {
            if(prime[i]) ans.push_back(i);
        }
        int si = ans.size();
        vector<long long> prefix(si,0);
        prefix[0] = ans[0];
        for(int i = 1; i<si; i++) {
            prefix[i] = ans[i]+prefix[i-1];
            if(prefix[i] <= n && prime[prefix[i]]) largest = max(largest,(int)prefix[i]);
        }
        // for(auto i: ans) {
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        // for(auto i: prefix) {
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        return largest;
    }
};