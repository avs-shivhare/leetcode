class Solution {
public:
    long long gcd(long long a,long long b) {
        if(a == 0) return b;
        if(b == 0) return a;
        if(a >= b) return gcd(a%b,b);
        return gcd(a,b%a);
    }
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;
        for(int i = 0; i<n; i++) {
            long long l = nums[i],g = nums[i];
            long long p = nums[i];
            for(int j = i+1; j<n; j++) {
                p *= nums[j];
                g = gcd(nums[j],g);
                l = l*nums[j]/gcd(l,nums[j]);
                //cout<<i<<" "<<j<<" "<<p<<" "<<l<<endl;
                if(p == l*g) ans = max(ans,j-i+1);
                //else break;
                if(p > 1e9) break; 
            }
        }
        return ans;
    }
};