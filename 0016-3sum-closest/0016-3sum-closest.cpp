class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int diff = 1e9;
        int n = nums.size();
        int ans = 0;
        for(int i =0; i<n; i++) {
            int j = i+1;
            int k = n-1;
            while(j<k) {
                int sum = nums[i]+nums[j]+nums[k];
                if(sum == target) return target;
                else if(abs(target-sum) < diff) {
                    ans = sum;
                    diff= abs(target-sum);
                }
                else if(sum > target) k--;
                else j++;
            }
        }
        return ans;
    }
};