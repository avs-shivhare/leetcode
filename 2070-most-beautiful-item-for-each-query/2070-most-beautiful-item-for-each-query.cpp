class Solution {
public:
    int find(vector<vector<int>> &nums,int value) {
        int low = 0,high = nums.size()-1;
        int ind = -1;
        while(low <= high) {
            int mid = (low+high)>>1;
            if(nums[mid][0] <= value) {
                ind = mid;
                low = mid+1;
            }
            else high = mid-1;
        }
        return ind;
    }
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        vector<int> ans;
        int n = items.size();
        sort(items.begin(),items.end());
        int prefix[n];
        memset(prefix,0,sizeof(prefix));
        prefix[0] = items[0][1];
        for(int i =1; i<n; i++) {
            prefix[i] = max(prefix[i-1],items[i][1]);
        }
        for(auto i: queries) {
            int ind =  find(items,i);
            if(ind == -1) ans.push_back(0);
            else ans.push_back(prefix[ind]);
        }
        return ans;
    }
};