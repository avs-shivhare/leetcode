class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        int cnt = 0;
        int el = 0;
        for(int i = 0; i<n; i++) {
            if(el == nums[i]) cnt++;
            else {
                el = nums[i];
                cnt = 1;
            }
            if(cnt <= k) {
                ans.push_back(el);
            }
        }
        return ans;
    }
};