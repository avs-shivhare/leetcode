class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> temp;
        int n = nums.size();
        for(int i = 0; i<n; i++) {
            if(nums[i] == key) temp.push_back(i);
        }
        int j = 0;
        vector<int> ans;
        for(int i = 0; i<n && j<temp.size(); i++) {
            if(abs(temp[j]-i) <= k) ans.push_back(i);
            else if(temp[j] < i) {
                j++;
                if(j<temp.size() && abs(temp[j]-i) <= k) ans.push_back(i);
            }
        }
        return ans;
    }
};