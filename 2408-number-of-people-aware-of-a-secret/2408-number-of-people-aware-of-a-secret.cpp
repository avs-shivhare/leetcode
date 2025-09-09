class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        queue<pair<int,int>> q;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q2;
        int cnt = 0;
        int mod = 1e9+7;
        long long ans = 1;
        long long sum = 0;
        q.push({1,1});
        while(cnt++ < n) {
            while(!q.empty() && cnt-q.front().first >= delay) {
                q2.push({q.front()});
                sum += q.front().second;
                sum %= mod;
                q.pop();
            }
            while(!q2.empty() && cnt-q2.top().first >= forget) {
                //cout<<q2.top().first<<" -> "<<q2.top().second<<endl;
                sum -= q2.top().second;
                sum = (sum+mod)%mod;
                ans = (ans-q2.top().second+mod)%mod;
                q2.pop();
            }
            if(!q2.empty()) {
                q.push({cnt,sum});
                ans += sum;
                ans %= mod;
            }
            //cout<<cnt<<" "<<ans<<" "<<sum<<endl;
        }
        return ans;
    }
};