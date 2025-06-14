class Solution {
public:
    bool check(vector<int> &nums,long long mid,int &p) {
        int n = nums.size();
        int cnt = 0;
        for(int i = 1; i<n; i++) {
            if(abs(nums[i]-nums[i-1]) <= mid) {
                cnt++;
                i++;
            }
        }
        return cnt >= p;
    } 
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        int ans = 1e9;
        int n = nums.size();
        long long l = 0,r = nums[n-1]-nums[0];
        while(l<=r) {
            long long mid = (l+r)>>1;
            
            if(check(nums,mid,p)) {
                ans = mid;
                r = mid-1;
            } 
            else l = mid+1;
        }
        return ans;
    }
};