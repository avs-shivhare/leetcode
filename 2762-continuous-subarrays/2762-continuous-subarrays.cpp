class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long ans = 0;
        int l = 0,r = 0;
        int n = nums.size();
        unordered_map<long long,int> mpp;
        while(r<n) {
            bool flag = true;
            if(mpp.count(nums[r]) || mpp.empty()) {
                mpp[nums[r]]++;
            }
            else {
                for(auto i: mpp) {
                    long long x = abs(i.first-nums[r]);
                    if(0<= x && x<= 2) {

                    }
                    else {
                        flag = false;
                        break;
                    }
                }
                mpp[nums[r]]++;
            }
            while(l<=r && !flag) {
                mpp[nums[l]]--;
                if(mpp[nums[l]] == 0) mpp.erase(nums[l]);
                bool t = true;
                for(auto i: mpp) {
                    //cout<<i.first<<endl;
                    long long x = abs(i.first-nums[r]);
                    if(0<= x && x<= 2) {

                    }
                    else {
                        //cout<<x<<endl;
                        t = false;
                        break;
                    }
                }
                flag = t;
                l++;
            }
            if(flag) {
                //cout<<r<<" -> "<<l<<endl;
                ans += r-l+1;
            }
            r++;
        }
        return ans;
    }
};