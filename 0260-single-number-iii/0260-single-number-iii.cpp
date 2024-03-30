class Solution {
public:
    //unordered map
    // vector<int> singleNumber(vector<int>& nums) {
    //     unordered_map<int,int> mpp;
    //     vector<int> ans;
    //     for(int i: nums) {
    //         mpp[i]++;
    //     }
    //     for(auto i: mpp) {
    //         if(i.second == 1) ans.push_back(i.first);
    //     }
    //     return ans;
    // }

    //bit manipulation 
    vector<int> singleNumber(vector<int>& nums) {
        long long r = 0;
        for(int i: nums) r = (r^i);
        int one =0,zero =0;
        int rightShift = (r & -r);
        for(int i: nums) {
            if(i & rightShift) one = (one^i);
            else zero = (zero^i);
        }
        return {one,zero};
    }
};