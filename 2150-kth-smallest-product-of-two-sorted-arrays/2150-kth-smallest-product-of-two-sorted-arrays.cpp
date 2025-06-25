class Solution {
public:
    bool check(vector<int> &nums1,long long &k,long long &target,vector<int> &nums) {
        long long cnt = 0;
        for(auto i: nums) {
            if(i == 0) {
                if(target >= 0) cnt += nums1.size();
            }
            else if(i > 0) {
                int l = 0,r = nums1.size()-1;
                int temp = 0;
                while(l<=r) {
                    int mid = (l+r)>>1;
                    if((long long)i*(long long)nums1[mid] <= target) {
                        temp = mid+1;
                        l = mid+1;
                    }
                    else r = mid-1;
                }
                cnt += temp;
            }
            else {
                int l = 0,r = nums1.size()-1;
                int temp = nums1.size();
                while(l<=r) {
                    int mid = (l+r)>>1;
                    if((long long)i*(long long)nums1[mid] <= target) {
                        temp = mid;
                        r = mid-1;
                    }
                    else l = mid+1;
                }
                cnt += nums1.size()-temp;
            }
        }
        //cout<<target<<" "<<cnt<<endl;
        return cnt >= k;
    }
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {    
        long long l = -1e15,r = 1e15;
        long long ans = 0;
        while(l<=r) {
            long long mid = (l+r)>>1;
            if(check(nums1,k,mid,nums2)) {
                ans = mid;
                r = mid-1;
            }
            else l = mid+1;
        }
        return ans;
    }
};