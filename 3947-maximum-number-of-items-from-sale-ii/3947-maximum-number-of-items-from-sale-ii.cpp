class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        unordered_map<long long,long long> mpp;
        for(auto &i: items) {
            mpp[i[0]]++;
        }
        unordered_map<int,int> free;
        for(auto &i: mpp) {
            long long x = i.first;
            long long sq = sqrt(x);
            for(long long j = 1; j<=sq; j++) {
                if(x%j == 0) {
                    if(j != x) free[j] += i.second;
                    if(j != x/j && x/j != x) free[x/j] += i.second;
                }
            }
            if(i.second > 1) {
                free[i.first] += i.second-1;
            }
        }
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> q;
        int mini = 0;
        for(int i = 0; i<n; i++) {
            if(items[mini][1] > items[i][1]) mini = i;
            if(free[items[i][0]]) q.push({items[i][1],i});
        }
        // for(auto &i: free) {
        //     cout<<i.first<<" "<<i.second<<endl;
        // }
        long long cnt = 0;
        while(!q.empty()) {
            long long cost = q.top().first;
            int ind = q.top().second;
            if(2ll*items[mini][1] > cost && budget >= cost) {
                long long div = 1ll*budget/items[ind][1];
                div = min(div,(long long)free[items[ind][0]]);
                budget -= cost*div;
                cnt += 2ll*div;
                //cout<<ind<<" "<<div<<" "<<cost<<endl;
            }
            q.pop();
        }
        if(budget >= items[mini][1]) {
            cnt += budget/items[mini][1];
        }
        return cnt;
    }
};