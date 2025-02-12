class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int,multiset<int,greater<int>>> mpp;
        for(auto i: nums) {
            int sum = 0;
            int val = i;
            while(i) {
                sum += (i%10);
                i /= 10;
            }
            mpp[sum].insert(val);
        }
        int ans = -1;
        for(auto i: mpp) {
            if(i.second.size() >= 2) {
                int first = *(i.second.begin());
                int second = *(next(i.second.begin()));
                ans = max(ans,first+second);
            }
        }
        return ans;
    }
};