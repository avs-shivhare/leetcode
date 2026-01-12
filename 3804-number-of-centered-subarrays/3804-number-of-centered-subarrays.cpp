class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for(int i = 0; i<n; i++) {
            unordered_set<int> st;
            int sum = 0;
            for(int j = i; j<n; j++) {
                st.insert(nums[j]);
                sum += nums[j];
                if(st.find(sum) != st.end()) cnt++;
            }
        }
        return cnt;
    }
};