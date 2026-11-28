class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        unordered_map<int,int> mpp;
        for(auto &j: items) {
            long long x = j[0];
            long long sq = sqrt(x);
            for(int i = 1; i<=sq; i++) {
                if(x%i == 0) {
                    mpp[i]++;
                    if(i != x/i) mpp[x/i]++;
                }
            }
        }
        sort(items.begin(),items.end(),[&](auto &a,auto &b){
            if(a[1] == b[1]) return a[0] < b[0];
            return a[1] < b[1];
        });
        long long ans = 0;
        for(auto &i: items) {
            long long x = i[1];
            long long cnt = 0;
            if(mpp[i[0]] > 1) cnt = mpp[i[0]]-1;
            cnt = min(cnt,1ll*budget/i[1]);
            //cout<<i[0]<<" "<<i[1]<<" "<<cnt<<endl;
            if(2ll*cnt*items[0][1] >= cnt*x) {
                //cout<<2ll*cnt*items[0][1]<<" "<<(2ll*cnt*items[0][1] >= x && cnt > 1)<<endl;
                //cout<<i[0]<<" "<<i[1]<<" "<<cnt<<endl;
                budget -= x*cnt;
                ans += cnt*2ll;
            }
        }
        //cout<<budget<<endl;
        ans += 1ll*budget/items[0][1];
        return ans;
    }
};