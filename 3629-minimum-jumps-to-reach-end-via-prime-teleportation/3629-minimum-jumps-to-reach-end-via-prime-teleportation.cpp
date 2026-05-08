class Solution {
public: 
    vector<bool> prime;
    void find(int &n) {
        prime.resize(n+1,true);
        prime[0] = false;
        prime[1] = false;
        for(int i = 2; i*i<=n; i++) {
            if(prime[i]) {
                for(int j = i*i; j<=n; j+=i) {
                    prime[j] = false;
                }
            }
        }
        return;
    }
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        int max = *max_element(nums.begin(),nums.end());
        find(max);
        unordered_map<int,vector<int>> adj,mpp;
        for(int i = 0; i<n; i++) {
            mpp[nums[i]].push_back(i);
        }
        for(auto &i: mpp) {
            if(!prime[i.first]) continue;
            for(int j = i.first; j<=max; j+=i.first) {
                if(mpp.find(j) != mpp.end()) {
                    for(auto &k: mpp[j]) {
                        adj[i.first].push_back(k);
                    }
                }
            }
        }
        // for(auto &i: nums) {
        //     cout<<prime[i]<<" ";
        // }
        // cout<<endl;
        queue<pair<int,int>> q;
        vector<int> dist(n,INT_MAX);
        q.push({0,0});
        dist[0] = 0; 
        while(!q.empty()) {
            int ind = q.front().first;
            int c = q.front().second;
            q.pop();
            //cout<<ind<<" "<<c<<endl;
            if(dist[ind] < c) continue;
            if(ind+1 < n && dist[ind+1] > c+1) {
                dist[ind+1] = c+1;
                q.push({ind+1,c+1});
            }
            if(ind-1 >= 0 && dist[ind-1] > c+1) {
                dist[ind-1] = c+1;
                q.push({ind-1,c+1});
            }
            if(prime[nums[ind]]) {
                prime[nums[ind]] = false;
                for(auto &i: adj[nums[ind]]) {
                    if(dist[i] > c+1) {
                        dist[i] = c+1;
                        q.push({i,c+1});
                    }
                }
            }
        }
        return dist[n-1];
    }
};