class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        for(auto i: nums) mpp[i]++;
        int sum = 0;
        for(auto &i: mpp) {
            if(i.second%k == 0) sum += i.second*i.first;
        }
        return sum;
    }
};