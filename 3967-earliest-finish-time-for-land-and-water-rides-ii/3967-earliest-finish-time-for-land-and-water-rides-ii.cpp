class Solution {
public:
    class compare {
        public:
        bool operator()(pair<int,int> a,pair<int,int> b) {
            return a.first+a.second < b.first+b.second;
        }
    };
    int earliestFinishTime(vector<int>& ls, vector<int>& ld, vector<int>& ws, vector<int>& wd) {
        int n = ls.size();
        int m = ws.size();
        vector<pair<int,int>> a,b;
        for(int i = 0; i<n; i++) {
            a.push_back({ls[i],ld[i]});
        }
        for(int i = 0; i<m; i++) {
            b.push_back({ws[i],wd[i]});
        }
        sort(a.begin(),a.end(),compare());
        sort(b.begin(),b.end());
        // for(auto i: a) {
        //     cout<<"[ "<<i.first<<" "<<i.second<<"],";
        // }
        // cout<<endl;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> q,q2;
        int mini = INT_MAX;
        for(int i = 0; i<m; i++) {
            q.push({b[i].first+b[i].second,i});
        }
        long long ans = 1e18;
        int j = 0;
        for(int i = 0; i<n; i++) {
            long long last = a[i].first+a[i].second;
            while(j<m && b[j].first <= last) {
                mini = min(mini,b[j].second);
                j++;
            }
            while(!q.empty() && q.top()[1] < j) q.pop();
            long long x = 1e18;
            if(!q.empty()) {
                x = q.top()[0];
            }
            x = max(last,x);
            //cout<<i<<" -> "<<j<<" "<<last+mini<<" "<<x<<endl;
            ans = min({ans,mini+last,x});
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end(),compare());
        mini = 1e9;
        // for(auto i: b) {
        //     cout<<"[ "<<i.first<<" "<<i.second<<"],";
        // }
        // cout<<endl;
        for(int i = 0; i<n; i++) {
            q2.push({a[i].first+a[i].second,i});
        }
        j = 0;
        for(int i = 0; i<m; i++) {
            long long last = b[i].first+b[i].second;
            while(j<n && a[j].first <= last) {
                mini = min(mini,a[j].second);
                j++;
            }
            while(!q2.empty() && q2.top()[1] < j) q2.pop();
            long long x = 1e18;
            if(!q2.empty()) x = q2.top()[0];
            x = max(last,x);
            //cout<<i<<" -> "<<j<<" "<<last+mini<<" "<<x<<endl;
            ans = min({ans,last+mini,x});
        }
        return ans;
    }
};