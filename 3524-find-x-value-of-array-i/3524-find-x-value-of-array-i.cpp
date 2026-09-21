class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k,0), prev(k,0);
        for(auto &i: nums) {
            vector<long long> curr(k,0);
            curr[i%k]++;
            for(int j = 0; j<k; j++) {
                curr[(j*(i%k))%k] += prev[j]; 
            }
            for(int j = 0; j<k; j++) {
                ans[j] += curr[j];
            }
            prev = curr;
        }
        return ans;
    }
};