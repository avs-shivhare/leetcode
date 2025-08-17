class Solution {
public:
    int lower(vector<long long> &arr,int l,int r,long long el) {
        int ans = l;
        while(l<=r) {
            int mid = (l+r)>>1;
            if(arr[mid] <= el) {
                ans = mid;
                l = mid+1;
            }
            else r = mid-1;
        }
        return ans;
    }
    long long perfectPairs(vector<int>& nums) {
        vector<long long> arr;
        for(auto i: nums) {
            arr.push_back(abs(1ll*i));
        }
        sort(arr.begin(),arr.end());
        int n = arr.size();
        long long ans = 0;
        for(int i = 0; i<n; i++) {
            ans += lower(arr,i,n-1,2ll*arr[i])-i;
        }
        return ans;
    }
};