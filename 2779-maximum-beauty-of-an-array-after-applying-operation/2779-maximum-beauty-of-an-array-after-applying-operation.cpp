class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int ans = 0,cnt = 0;
        vector<pair<int,int>> temp;
        for(auto i: nums) {
            temp.push_back({i-k,-1});
            temp.push_back({i+k,2});
        }
        sort(temp.begin(),temp.end());
        for(auto i: temp) {
            if(i.second == -1) cnt++;
            else if(i.second == 2) cnt--;
            ans = max(ans,cnt);
        }
        return ans;
    }
};