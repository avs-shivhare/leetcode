class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int cnt = 0;
        for(auto i: nums) {
            string temp = to_string(i);
            if((temp.size()&1) == 0) cnt++;
        }
        return cnt;
    }
};