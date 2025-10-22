class Solution {
public:
    int lower(vector<int> &nums,long long el) {
        int ans = -1;
        int l = 0,r = nums.size()-1;
        while(l<=r) {
            int mid = (l+r)>>1;
            if(nums[mid] >= el) {
                ans = mid;
                r = mid-1;
            }
            else l = mid+1;
        }
        return ans;
    }

    int upper(vector<int> &nums,long long el) {
        int ans = -1;
        int l = 0,r = nums.size()-1;
        while(l<=r) {
            int mid = (l+r)>>1;
            if(nums[mid] <= el) {
                ans = mid;
                l = mid+1;
            }
            else r = mid-1;
        }
        return ans;
    }

    int maxFrequency(vector<int>& nums, int k, int m) {
        unordered_map<int,int> mpp;
        for(auto i: nums) {
            mpp[i]++;
        }
        int ans = 0;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(auto i: nums) {
            int l = lower(nums,1ll*i-k);
            int r = upper(nums,1ll*i+k);
            if(l != -1 && r != -1) {
                int len = r-l+1;
                ans = max(ans,min(len-mpp[i],m)+mpp[i]);
            }
        }
        if(ans >= m) return ans;
        int ans2 = 0;
        for(int i = 0; i<n; i++) {
            int l = lower(nums,nums[i]-2ll*k);
            ans2 = max(ans2,i-l+1);
        }
        return max(ans,min(m,ans2));
    }
};