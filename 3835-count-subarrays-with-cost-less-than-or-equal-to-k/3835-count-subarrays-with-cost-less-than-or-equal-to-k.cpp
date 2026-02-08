class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long ans = 0;
        deque<pair<long long,int>> maxi,mini;
        int l = 0,r = 0;
        int n = nums.size();
        while(r<n) {
            while(!maxi.empty() && maxi.back().first <= nums[r]) maxi.pop_back();
            while(!mini.empty() && mini.back().first >= nums[r]) mini.pop_back();
            while(!maxi.empty() && maxi.front().second < l) maxi.pop_front();
            while(!mini.empty() && mini.front().second < l) mini.pop_front();
            maxi.push_back({nums[r],r});
            mini.push_back({nums[r],r});
            while(!maxi.empty() && !mini.empty() && (maxi.front().first-mini.front().first)*1ll*(r-l+1) > k) {
                l++;
                while(!maxi.empty() && maxi.front().second < l) maxi.pop_front();
                while(!mini.empty() && mini.front().second < l) mini.pop_front();
            }
            if(!maxi.empty() && !mini.empty() && (maxi.front().first-mini.front().first)*1ll*(r-l+1) <= k) ans += r-l+1;
            r++;
        }
        return ans;
    }
};