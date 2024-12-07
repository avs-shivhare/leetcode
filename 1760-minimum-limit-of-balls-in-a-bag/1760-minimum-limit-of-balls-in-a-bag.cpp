class Solution {
public:
    bool check(vector<int> &nums,int maxi,int &mid) {
        int cnt = 0;
        for(auto i: nums) {
            if(i > mid) cnt += ceil((double)i/mid)-1;
        }
        return cnt <= maxi;
    }
    int minimumSize(vector<int>& nums, int maxi) {
        int l = 1, r= *max_element(nums.begin(),nums.end());
        int ans = r;
        while(l<=r) {
            int mid = (l+r)>>1;
            //cout<<mid<<endl;
            if(check(nums,maxi,mid)) {
                ans = mid;
                r = mid-1;
                //cout<<"done"<<endl;
            }
            else l = mid+1;
        }
        return ans;
    }
};