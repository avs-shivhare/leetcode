class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        bool flag = false;
        vector<int> ans;
        int n = nums.size();
        for(int i =0; i<n; i++) {
            if(i+k > n) break;
            if(!flag) {
                flag = true;
                for(int j = i+1; j<n && j-i<k; j++) {
                    //cout<<nums[j]<<" "<<nums[j-1]<<endl;
                    if(nums[j]-1 != nums[j-1]) {
                        flag = false;
                        break;
                    }
                }
            }
            else {
                if(nums[i+k-2]+1 != nums[i+k-1]) {
                    flag = false;
                }
            }
            if(flag || k == 1) {
                ans.push_back(nums[i+k-1]);
            }
            else {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};