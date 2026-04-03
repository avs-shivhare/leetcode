class Solution {
public:
    long long find(vector<int> &w,long long left,long long right) {
        if(left>right) return 0;
        long long l = lower_bound(w.begin(),w.end(),left)-w.begin();
        long long r = upper_bound(w.begin(),w.end(),right)-w.begin();
        return r-l;
    }
    int maxWalls(vector<int>& r, vector<int>& d, vector<int>& w) {
        vector<pair<long long,long long>> temp;
        int n = r.size();
        int m = w.size();
        for(int i = 0; i<n; i++) {
            temp.push_back({r[i],d[i]});
        }
        sort(temp.begin(),temp.end());
        sort(w.begin(),w.end());
        long long currl = temp[0].first-temp[0].second;
        long long currr = temp[0].first;
        vector<vector<long long>> dp(n,vector<long long>(2,0));
        dp[0][0] = find(w,currl,currr);
        currl = temp[0].first;
        currr = min(temp[0].first+temp[0].second,(n>1? temp[1].first-1: (long long)1e18)); 
        dp[0][1] = find(w,currl,currr);
        long long ans = max(dp[0][0],dp[0][1]);
        for(int i = 1; i<n; i++) {
            currl = max(temp[i-1].first+1,temp[i].first-temp[i].second);
            currr = temp[i].first;
            long long il = find(w,currl,currr);
            currl = temp[i-1].first;
            currr = min(temp[i-1].first+temp[i-1].second,temp[i].first-1);
            long long pr = find(w,currl,currr);
            currl = temp[i-1].first;
            currr = temp[i].first;
            long long total = find(w,currl,currr);
            dp[i][0] = dp[i-1][0]+il;
            if(temp[i-1].first+temp[i-1].second >= temp[i].first-temp[i].second) {
                dp[i][0] = max(dp[i][0],(dp[i-1][1]-pr)+total);
            }
            else {
                dp[i][0] = max(dp[i][0],dp[i-1][1]+il);
            }
            currl = temp[i].first;
            currr = min(temp[i].first+temp[i].second,(i+1<n ? temp[i+1].first-1: (long long)1e18));
            long long ir = find(w,currl,currr);
            dp[i][1] = max(dp[i-1][0],dp[i-1][1])+ir;
            ans = max({ans,dp[i][0],dp[i][1]});
        }
        return ans;
    }
};