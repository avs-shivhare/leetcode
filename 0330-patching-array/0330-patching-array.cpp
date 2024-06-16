class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int x = nums.size();
        long long sum = 1;
        long long maxi = 0;
        int i = 0;
        int ans = 0;
        while(sum <= n) {
            if(i<x && nums[i] <= sum) {
                sum += nums[i];
                i++;
            }
            else {
                sum = sum*2;
            }
            ans++;
            //cout<<sum<<endl;
        }
        return ans-i;
    }
};