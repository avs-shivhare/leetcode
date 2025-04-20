class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k,0), prev(k,0);
        for(auto i: nums) {
            int rem = i%k;
            vector<long long> curr(k,0);
            curr[rem]++;
            for(int j = 0; j<k; j++) {
                curr[((long long)rem*j)%k] += prev[j];
            }
            for(int j = 0; j<k; j++) {
                ans[j] += curr[j]; 
            }
            prev = curr;
        }
        return ans;
    }
};