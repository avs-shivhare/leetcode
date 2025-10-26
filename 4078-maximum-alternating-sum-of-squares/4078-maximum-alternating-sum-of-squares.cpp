class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long ans = 0;
        vector<long long> temp;
        int n = nums.size();
        for(auto &i: nums) {
            temp.push_back(1ll*i*i);
        }
        sort(temp.begin(),temp.end());
        int l = 0, r= n-1;
        if(n&1) {
            ans += temp[r];
            r--;
        }
        while(l<r) {
            ans += temp[r];
            r--;
            ans -= temp[l];
            l++;
        }
        return ans;
    }
};