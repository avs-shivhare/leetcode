class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int,int> mpp;
        int el = 0;
        for(auto i: nums) {
            mpp[i]++;
            if(mpp[el] < mpp[i]) {
                el = i;
            }
        }
        int cnt = 0;
        int n = nums.size();
        for(int i = 0; i<n; i++) {
            if(nums[i] == el) {
                cnt++;
            }
            if(cnt > (i+1)/2 && (mpp[el]-cnt) > (n-i-1)/2) return i;
        }
        return -1;
    }
};