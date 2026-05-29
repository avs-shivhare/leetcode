class Solution {
public:
    int minElement(vector<int>& nums) {
        int mini = 1e9;
        for(auto &i: nums) {
            int sum = 0;
            while(i) {
                sum += i%10;
                i /= 10;
            }
            mini = min(mini,sum);
        }
        return mini;
    }
};