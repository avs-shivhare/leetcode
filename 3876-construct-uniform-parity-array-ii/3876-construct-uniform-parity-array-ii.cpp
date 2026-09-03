class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int odd = 1e9+1;
        for(auto &i: nums1) {
            if(i&1) odd = min(odd,i);
        }
        bool flag = true,flag2 = true;
        for(auto &i: nums1) {
            if((i&1) == 0) continue;
            if(odd >= i) {
                flag = false;
                break;
            }
        }
        for(auto &i: nums1) {
            if(i&1) continue;
            if(odd >= i) {
                flag2 = false;
                break;
            }
        }
        return flag || flag2;
    }
};