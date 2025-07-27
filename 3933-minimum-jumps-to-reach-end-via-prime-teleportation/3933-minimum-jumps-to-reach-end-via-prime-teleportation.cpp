class Solution {
public:
    map<int,set<int>> adj;
    vector<int> spf;
    void prime(int n) {
        for(int i = 2; i*i<n; i++) {
            if(spf[i] == i) {
                for(int j = i*i; j<n; j+=i) {
                    if(spf[j] == j) spf[j] = i;
                } 
            }
        }
        return;
    }
    void find(int x,int ind) {
        while(x > 1) {
            adj[spf[x]].insert(ind);
            x /= spf[x];
        }
        return;
    }
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(),nums.end());
        spf.resize(maxi+1,0);
        iota(spf.begin(),spf.end(),0);
        prime(maxi+1);
        for(int i = 0; i<n; i++) {
            if(nums[i]>1) find(nums[i],i);
        }
        queue<pair<set<int>,vector<int>>> q;
        vector<int> dist(n,1e9);
        dist[0] = 0;
        set<int> x;
        q.push({x,{0,0}});
        while(!q.empty()) {
            auto all = q.front().first;
            int cost = q.front().second[0];
            int ind = q.front().second[1];
            if(ind == n-1) return cost;
            q.pop();
            if(ind +1 < n && dist[ind+1] > cost+1) {
                dist[ind+1] = cost+1;
                q.push({all,{cost+1,ind+1}});
            }
            if(ind > 0 && dist[ind-1] > cost+1) {
                dist[ind-1] = cost+1;
                q.push({all,{cost+1,ind-1}});
            }
            if(nums[ind] > 1 && spf[nums[ind]]== nums[ind] && all.count(nums[ind]) == 0) {
                //cout<<nums[ind]<<endl;
                all.insert(nums[ind]);
                for(auto i: adj[nums[ind]]) {
                    if(i == ind) continue;
                    if(dist[i] > cost+1) {
                        q.push({all,{cost+1,i}});
                        dist[i] = cost+1;
                    }
                }
            }
        }
        return -1;
    }
};