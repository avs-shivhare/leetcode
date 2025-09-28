class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int n = nums.size();
        vector<bool> vis(n,false);
        long long sum = 0;
        for(int i = 1; i<n-1; i++) {
            if(nums[i-1] >= nums[i] && nums[i] <= nums[i+1]) return -1;
            //else if(nums[i] == nums[i-1] || nums[i] == nums[i+1]) return -1;
        }
        sum += nums[0];
        if(nums[0] > nums[1]) {
            vis[0] = true; 
        }
        vis[n-1] = true;
        for(int i = 1; i<n-1; i++) {
            if(nums[i-1] <= nums[i] && nums[i] > nums[i+1]) {
                vis[i] = true;
            }
            sum += nums[i];
        }
        sum += nums[n-1];
        //cout<<sum<<endl;
        long long ans = sum;
        long long sum2 = 0;
        for(int i = 0; i<n; i++) {
            if(vis[i]) {
                ans = min({ans,abs(sum2-sum),abs((sum2+nums[i])-(sum-nums[i]))});
                // cout<<abs((sum2+nums[i])-(sum-nums[i]))<<" "<<abs(sum2-sum)<<endl;
                // cout<<"sum ->"<<sum<<" "<<sum2<<endl;
            }
            sum2 += nums[i];
            sum -= nums[i];
        }
        return ans;
    }
};