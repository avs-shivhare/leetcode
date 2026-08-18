class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        int n = nums.size();
        for(int i = 0; i<n; i++) {
            if(i+k > n) break;
            unordered_set<int> st;
            for(int j = i; j<i+k; j++) {
                st.insert(nums[j]);
            }
            for(auto &j: st) mpp[j]++;
        }
        int ans = -1;
        for(auto &i: mpp) {
            if(i.second == 1) ans = max(ans,i.first);
        }
        return ans;
    }
};