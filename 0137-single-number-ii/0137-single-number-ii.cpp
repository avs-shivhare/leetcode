class Solution {
public:
    //Using bit manupulation
    int singleNumber(vector<int>& nums) {
        int one =0,two =0;
        int n = nums.size();
        for(int i =0; i<n; i++) {
            one = (one^nums[i]) & ~(two);
            two = (two^nums[i]) & ~(one);
        }
        return one;
    }

    //using unordered map
    // int singleNumber(vector<int>& nums) {
    //     unordered_map<int,int> mpp;
    //     for(int i: nums) {
    //         mpp[i]++;
    //     }
    //     for(auto i: mpp) {
    //         if(i.second == 1) return i.first;
    //     }
    //     return 0;
    // }
};