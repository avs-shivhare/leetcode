class Solution {
public:
    int f(int ind,int w,int k,vector<int> &profit,vector<int> & capital,vector<vector<vector<int>>> &dp) {
        if(ind == profit.size()) return w;
        if(k == 0) return w;
        if(dp[ind][w][k] != -1) return dp[ind][w][k];
        int notTake = 0,take = 0;
        notTake = f(ind+1,w,k,profit,capital,dp);
        if(capital[ind] <= w) {
            take = f(ind+1,w+profit[ind],k-1,profit,capital,dp);
        }
        return dp[ind][w][k]= max(take,notTake);
    }
    static bool comparator(pair<int,int> t1,pair<int,int> t2) {
        if(t1.first > t2.first) return false;
        else if(t1.first < t2.first) return true;
        else if(t1.second > t2.second) return false;
        return true;
    }
    int search(vector<pair<int,int>> &arr,int &n,int w) {
        int low = 0,high = arr.size()-1;
        int ans = -1;
        while(low <= high) {
            int mid = (low+high)>>1;
            if(arr[mid].first <= w) {
                ans = mid;
                low = mid+1;
            }
            else high = mid-1;
        }
        return ans;
    }
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        // int n = profits.size();
        // long long sum = accumulate(profits.begin(),profits.end(),0);
        // vector<vector<vector<int>>> dp(n, vector<vector<int>>(sum + w + 1, vector<int>(k + 1, -1)));
        // map<pair<int,pair<int,int>>,int> mpp;
        // return f(0,w,k,profits,capital,dp);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        priority_queue<pair<int,int>> pq;
        int n = profits.size();
        for(int i =0; i<n;i++) {
            q.push({capital[i],profits[i]});
        }
        vector<pair<int,int>> temp;
        //int ans = 0;
        while(k--) {
            while(!q.empty() && w >= q.top().first) {
                pq.push({q.top().second,q.top().first});
                q.pop();
            }
            if(pq.empty()) return w;
            //ans += pq.top().first;
            w += pq.top().first;
            pq.pop();
        }
        return w;
    }
};