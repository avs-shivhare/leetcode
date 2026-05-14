class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        vector<int> prefix(limit*2+2,0);
        int l = 0,r = nums.size()-1;
        //prefix[limit*2+1] -= 2;
        while(l<r) {
            int mini = min(nums[l],nums[r])+1;
            int maxi = max(nums[l],nums[r])+limit+1;
            prefix[2] += 2;
            prefix[mini] -= 1;
            prefix[maxi] += 1;
            int sum = nums[l]+nums[r];
            prefix[sum] -= 1;
            prefix[sum+1] += 1;
            l++;
            r--;
        } 
        int ans = INT_MAX;
        int sum = 0;
        for(int i = 2; i<=2*limit; i++) {
            //cout<<prefix[i]<<" ";
            sum += prefix[i];
            ans = min(ans,sum);
        }
        return ans;
    }
};