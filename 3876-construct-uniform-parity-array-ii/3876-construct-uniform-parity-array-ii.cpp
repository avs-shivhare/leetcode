class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        int mini = INT_MAX;
        int mini2 = INT_MAX;
        for(auto &i: nums) {
            if(i&1) {
                mini = min(mini,i);
            }
            else mini2 = min(mini2,i);
        }
        bool flag = true,flag2 = true;
        for(auto &i: nums) {
            if(i&1) {
                if(1ll*i-mini < 1) flag2 = false; 
            }
            else {
                if(1ll*i-mini < 1) flag = false;
            }
        }
        return flag || flag2;
    }
};