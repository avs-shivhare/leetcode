class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int ans = 0;
        int mod = 1e9+7;
        int odd = 0,even = 1;
        long long sum = 0;
        for(auto i: arr) {
            sum += i;
            if(sum&1) {
                ans = (ans+even)%mod;
                odd++;
            }
            else {
                ans = (ans+odd)%mod;
                even++;
            }
            //cout<<ans<<" "<<sum<<" "<<even<<" "<<odd<<endl;
        }
        return ans;
    }
};