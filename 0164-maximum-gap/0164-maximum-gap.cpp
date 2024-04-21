class Solution {
public:
    // solution with time complexity is O(2nlogn)
    // int maximumGap(vector<int>& nums) {
    //     if(nums.size() <2) return 0;
    //     set<int> st;
    //     for(int i: nums) st.insert(i);
    //     int ans = 0;
    //     int prev = -1;
    //     for(int i: st) {
    //         if(prev == -1) {
    //             prev = i;
    //             continue;
    //         }
    //         ans = max(ans,i-prev);
    //         prev = i;
    //     }
    //     return ans;
    // }

    //better solution with time complexity is O(nlogn)+O(n) and space complexity of O(1)
    int maximumGap(vector<int>& nums) {
        if(nums.size() <2) return 0;
        sort(nums.begin(),nums.end());
        int ans = 0;
        int n = nums.size();
        for(int i =0; i<n-1; i++) {
            ans = max(ans,nums[i+1]-nums[i]);
        }
        return ans;
    }
};