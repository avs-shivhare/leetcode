class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xOr =0;
        for(int i: nums) {
            xOr ^= i;
        }
        int x =0;
        for(x = 0; x<32; x++) {
            if((1<<x) & xOr) {
                break;
            }
        }
        int set = 0,unset = 0;
        for(int i: nums) {
            if((1<<x) & i) {
                set ^= i;
            }
            else {
                unset ^= i;
            }
        }
        return {set,unset};
    }
};