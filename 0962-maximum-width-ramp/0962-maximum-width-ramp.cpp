class Solution {
public:
    int upper(vector<pair<int,int>> &temp,int element) {
        int low =0,high = temp.size()-1;
        int ans = -1;
        while(low <= high) {
            int mid = (low+high)>>1;
            if(temp[mid].first >= element) {
                ans = temp[mid].second;
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }
        return ans;
    }
    int maxWidthRamp(vector<int>& nums) {
        vector<pair<int,int>> temp;
        int n = nums.size();
        for(int i = n-1; i>=0; i--) {
            if(temp.empty() || temp.back().first<= nums[i]) {
                temp.push_back({nums[i],i});
            }
        }
        int ans = 0;
        for(int i =0; i<n; i++) {
            int ind = upper(temp,nums[i]);
            if(ind == -1 && i >= ind) continue;
            ans = max(ans,ind-i);
        }
        return ans;
    }
};