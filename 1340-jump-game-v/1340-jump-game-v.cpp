class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        queue<pair<int,int>> q;
        vector<int> dist(n,0);
        for(int i = 0; i<n; i++) {
            q.push({i,1});
            dist[i] = 1;
        }
        while(!q.empty()) {
            int ind = q.front().first;
            int cnt = q.front().second;
            q.pop();
            if(dist[ind] > cnt) continue;
            for(int i = 1; i<=d && i+ind < n; i++) {
                if(arr[ind] > arr[ind+i]) {
                    if(dist[ind+i] < cnt+1) {
                        dist[ind+i] = cnt+1;
                        q.push({ind+i,cnt+1});
                    }
                }
                else break;
            }
            for(int i = 1; i<=d && ind-i >= 0; i++) {
                if(arr[ind] > arr[ind-i]) {
                    if(dist[ind-i] < cnt+1) {
                        dist[ind-i] = cnt+1;
                        q.push({ind-i,cnt+1});
                    }
                }
                else break;
            }
        }
        // for(auto &i: dist) cout<<i<<" ";
        // cout<<endl;
        return *max_element(dist.begin(),dist.end());
    }
};