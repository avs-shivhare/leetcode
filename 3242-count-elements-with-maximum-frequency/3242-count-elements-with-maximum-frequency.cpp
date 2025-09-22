class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> mpp;
        for(auto &i: nums) mpp[i]++;
        int maxi = 0;
        for(auto &i: mpp) maxi = max(maxi,i.second);
        int ans = 0;
        for(auto &i: mpp) {
            if(i.second == maxi) ans += i.second;
        }
        return ans;
    }
};