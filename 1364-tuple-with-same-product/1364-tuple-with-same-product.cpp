class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        unordered_map<int,int> mpp;
        int ans = 0;
        for(int i = 0; i<n; i++) {
            for(int j = i+1; j<n; j++) {
                ans += 8*mpp[nums[i]*nums[j]];
                mpp[nums[i]*nums[j]]++;
            }
        }
        // for(auto i: mpp) {
        //     if(i.second.size() == 1) continue;
        //     ans += (i.second.size())*8;
        // }
        return ans;
    }
};