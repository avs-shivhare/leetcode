class Solution {
public:
    int find(vector<int> &arr,int s,int sum) {
        int l = s+1;
        int r = arr.size()-1;
        int ans = s;
        while(l<=r) {
            int mid = (l+r)>>1;
            if(arr[mid] < sum) {
                ans = mid;
                l = mid+1;
            }
            else r = mid-1;
        }
        if(ans == s) return 0;
        return ans-s;
    }
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i<n; i++) {
            for(int j = i+1; j<n; j++) {
                int sum = nums[i]+nums[j];
                int x = find(nums,j,sum);
                ans += x;
                //cout<<j<<" "<<sum<<" "<<x<<endl;
            }
        }
        return ans;
    }
};