class Solution {
public:
    int low(vector<int> &arr,int el) {
        if(arr.empty()) return -1;
        int ans = -1;
        int l = 0,r = arr.size()-1;
        while(l<=r) {
            int mid = (l+r)>>1;
            if(arr[mid] >= el) {
                ans = mid;
                r = mid-1;
            }
            else l = mid+1;
        }
        return ans;
    }
    int high(vector<int> &arr,int el) {
        if(arr.empty()) return -1;
        int ans = -1;
        int l = 0,r = arr.size()-1;
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
    long long countFairPairs(vector<int>& nums, int l, int r) {
        vector<int> temp;
        long long ans = 0;
        for(auto i: nums) {
            int ind = low(temp,l-i);
            if(ind != -1) {
                int ind2 = high(temp,r-i);
                ans += ind2-ind+1;
            }
            auto x = upper_bound(temp.begin(),temp.end(),i);
            temp.insert(x,i);
        }
        return ans;
    }
};