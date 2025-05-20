class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> prefix(n+1,0);
        for(auto i: queries) {
            prefix[i[0]]++;
            prefix[i[1]+1]--;
        }
        int sum = 0;
        for(int i = 0; i<n; i++) {
            sum += prefix[i];
            if(sum < nums[i]) return false;
        }
        return true;
    }
};