class Solution {
public:
    int find(int &n,long long n1,long long n2) {
        int cnt = 0;
        while(n1<=n) {
            cnt += min((long long)n+1,n2)-n1;
            n1 *=10;
            n2 *= 10;
        }
        return cnt;
    }
    int findKthNumber(int n, int k) {
        k--;
        int ans = 1;
        while(k) {
            int temp = find(n,ans,ans+1);
            if(temp <= k) {
                k -= temp;
                ans++;
            }
            else {
                k--;
                ans *=10;
            }
        }
        return ans;
    }
};