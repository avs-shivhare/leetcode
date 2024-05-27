class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(),nums.end());
        for(int i =0; i<=maxi; i++) {
            bool flag = true;
            int cnt = 0;
            for(int x: nums) {
                if(i<= x) cnt++;
                if(cnt > i) {
                    flag = false;
                    break;
                }
            }
            if(flag && i == cnt) return cnt;
        }
        return -1;
    }
};