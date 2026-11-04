
class Solution {
public:
    long long dp[100001][16];
    multiset<long long> left,right;
    long long l = 0,r = 0;
    void balance() {
        int t = left.size()+right.size();
        while(right.size() < t/2) {
            auto x = prev(left.end());
            l -= *x;
            r += *x;
            right.insert(*x);
            left.erase(x);
        }
        while(left.size() < (t+1)/2) {
            auto x = right.begin();
            r -= *x;
            l += *x;
            left.insert(*x);
            right.erase(x);
        }
    }
    void add(long long x){
        if(left.empty() || x <= *prev(left.end())) {
            l += x;
            left.insert(x);
        }
        else {
            r += x;
            right.insert(x);
        }
        balance();
    }
    void remove(long long x) {
        auto it = left.find(x);
        if(it != left.end()) {
            l -= x;
            left.erase(it);
        }
        else {
            r -= x;
            right.erase(right.find(x));
        }
        balance();
    }
    long long cost() {
        int t = left.size()+right.size();
        long long m = *prev(left.end());
        if(t&1) return r-l+m;
        return r-l;
    }
    long long find(int i,int k,vector<int> &nums,int &x,vector<long long> &prefix) {
        if(k <= 0) return 0;
        if(i >= nums.size()) return 1e18;
        if(dp[i][k] != -1) return dp[i][k];
        long long ans = 1e18;
        if(i+x <= nums.size()) ans = min(ans,prefix[i]+find(i+x,k-1,nums,x,prefix));
        ans = min(ans,find(i+1,k,nums,x,prefix));
        return dp[i][k] = ans;
    }
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        memset(dp,-1,sizeof(dp));
        vector<long long> prefix(n,0);
        int l = 0,r = 0;
        while(r<n) {
            add(nums[r]);
            while(l<r && r-l+1 >x) {
                remove(nums[l]);
                l++;
            }
            if(r-l+1 == x) {
                prefix[l] = cost();
            }
            r++;
        }
        return find(0,k,nums,x,prefix);
    }
};