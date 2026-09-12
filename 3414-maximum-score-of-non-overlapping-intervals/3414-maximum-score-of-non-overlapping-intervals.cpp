class Solution {
public:
    long long dp[100001][5];
    vector<int> dp2[100001][5];
    int upper(vector<vector<int>> &arr,int el) {
        int l = 0, r = arr.size()-1;
        int ans = r+1;
        while(l<=r) {
            int mid = (l+r)>>1;
            if(arr[mid][0] > el) {
                ans = mid;
                r = mid-1;
            }
            else l = mid+1;
        }
        return ans;
    }
    pair<long long,vector<int>> find(int i,int cnt,vector<vector<int>> &arr) {
        if(cnt == 4) return {0,{}};
        if(i >= arr.size()) {
            return {0,{}};
        }
        return {dp[i][cnt],dp2[i][cnt]};
    }
    vector<int> maximumWeight(vector<vector<int>>& in) {
        memset(dp,-1,sizeof(dp));
        int n = in.size();
        vector<vector<int>> arr;
        for(int i = 0; i<n; i++) {
            arr.push_back({in[i][0],in[i][1],i,in[i][2]});
        }
        sort(arr.begin(),arr.end());
        for(int i = n-1; i>=0; i--) {
            for(int cnt = 0; cnt<4; cnt++) {
                auto take = find(upper(arr,arr[i][1]),cnt+1,arr);
                take.first += 1ll*arr[i][3];
                take.second.push_back(arr[i][2]);
                sort(take.second.begin(),take.second.end());
                auto notTake = find(i+1,cnt,arr);
                pair<long long,vector<int>> res;
                if(take.first > notTake.first) {
                    res = take;
                }
                else if(take.first < notTake.first) {
                    res = notTake;
                }
                else {
                    if(take.second < notTake.second) res = take;
                    else res = notTake;
                }
                dp[i][cnt] = res.first;
                dp2[i][cnt] = res.second;
            }
        }
        auto x = find(0,0,arr);
        return x.second;
    }
};