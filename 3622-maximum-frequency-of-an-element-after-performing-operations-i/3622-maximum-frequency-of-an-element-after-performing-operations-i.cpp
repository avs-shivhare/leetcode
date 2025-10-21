class Solution {
public:
    int upper(vector<int> &nums,int el) {
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

    int lower(vector<int> &nums,int el) {
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

    int maxFrequency(vector<int>& nums, int k, int m) {
        sort(nums.begin(),nums.end());
        unordered_map<int,int> mpp;
        for(auto i: nums) mpp[i]++;
        int l = nums.front()-k;
        int r = nums.back()+k;
        int ans = 0;
        for(int i = l; i<=r; i++) {
            int ll = lower(nums,i-k);
            int rr = upper(nums,i+k);
            //cout<<ll<<" "<<rr<<" "<<i<<endl;
            if(ll != -1 && rr != -1) {
                int len = rr-ll+1;
                ans = max(ans,min(len-mpp[i],m)+mpp[i]);
            }
        }
        return ans;
    }
};