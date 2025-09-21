class Solution {
public:
    int evenNumberBitwiseORs(vector<int>& nums) {
        int ans = 0;
        for(auto i: nums) {
            if((i&1) == 0) ans |= i;
        }
        return ans;
    }
};