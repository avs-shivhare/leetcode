class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        int cnt = 0;
        int prev = -1;
        for(auto i: nums) {
            if(prev <= i) {
                cnt++;
                prev = i;
            }
        }
        return cnt;
    }
};