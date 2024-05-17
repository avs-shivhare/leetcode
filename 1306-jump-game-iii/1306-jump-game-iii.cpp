class Solution {
public:
    // 1st approach using memorization with dp
    // bool f(int ind,vector<int> &arr,vector<int> &dp) {
    //     if(ind >= arr.size()) return false;
    //     if(ind <0) return false;
    //     if(arr[ind] == 0) return true;
    //     if(dp[ind] != -1) return dp[ind];
    //     dp[ind] = 0;
    //     bool l = false,r = false;
    //     l = f(ind-arr[ind],arr,dp);
    //     r = f(ind+arr[ind],arr,dp);
    //     return dp[ind] = l || r;
    // }
    // bool canReach(vector<int>& arr, int start) {
    //     int n = arr.size();
    //     vector<int> dp(n,-1);
    //     return f(start,arr,dp);
    // }


    // // 2nd approach using bfs
    // bool canReach(vector<int>& arr, int start) {
    //     int n = arr.size();
    //     vector<bool> vis(n,false);
    //     queue<int> q;
    //     if(arr[start] == 0) return true;
    //     int b = start-arr[start];
    //     int f = start+arr[start];
    //     vis[start] = true;
    //     if(f < n) q.push(f);
    //     if(b >= 0) q.push(b);
    //     while(!q.empty()) {
    //         int size = q.size();
    //         for(int i =0; i<size; i++) {
    //             int ind = q.front();
    //             q.pop();
    //             vis[ind] = true;
    //             if(arr[ind] == 0) return true;
    //             int f = ind + arr[ind];
    //             int b = ind - arr[ind];
    //             if(f < n && !vis[f]) q.push(f);
    //             if(b >=0 && !vis[b]) q.push(b);
    //         }
    //     }
    //     return false;
    // }

    // 3rd approach using queue
    bool canReach(vector<int>& arr, int start) {
        queue<int> q;
        q.push(start);
        int n = arr.size();
        vector<bool> vis(n,false);
        while(!q.empty()) {
            int ind = q.front();
            vis[ind] = true;
            q.pop();
            if(arr[ind] == 0) return true;
            if(ind-arr[ind] >=0 && !vis[ind-arr[ind]]) q.push(ind-arr[ind]);
            if(ind+arr[ind] < n && !vis[ind+arr[ind]]) q.push(ind+arr[ind]);
        }
        return false;
    }

};