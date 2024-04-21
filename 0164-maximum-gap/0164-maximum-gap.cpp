class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size() <2) return 0;
        set<int> st;
        for(int i: nums) st.insert(i);
        int ans = 0;
        int prev = -1;
        for(int i: st) {
            if(prev == -1) {
                prev = i;
                continue;
            }
            ans = max(ans,i-prev);
            prev = i;
        }
        return ans;
    }
};