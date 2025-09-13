class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        int n = nums.size();
        unordered_set<int> st(nums.begin(),nums.end());
        sum /= n;
        int mini = max(1,sum+1);
        while(true) {
            if(st.find(mini) == st.end()) return mini;
            mini++;
        }
        return -1;
    }
};