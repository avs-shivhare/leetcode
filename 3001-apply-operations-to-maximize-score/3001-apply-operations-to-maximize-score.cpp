class Solution {
public:
    int mod = 1e9+7;
    long long power(long long x,long long y) {
        if(x == 0) return 0;
        if(y == 0) return 1;
        if(y == 1) return x;
        long long ans = power(x,y/2)%mod;
        if(y&1) {
            return (((ans*ans)%mod)*x)%mod;
        }
        return (ans*ans)%mod;
    }
    int maximumScore(vector<int>& nums, int k) {
        vector<bool> vis(1e5+1,true);
        vis[0] = false;
        vis[1] = false;
        for(int i = 2; i*i<1e5+1; i++) {
            if(vis[i]) {
                for(int j = i*i; j<1e5+1; j+=i) {
                    vis[j] = false;
                }
            }
        }
        int n = nums.size();
        vector<int> fact(n,0);
        for(int i = 0; i<n; i++) {
            for(int j = 1; j*j<=nums[i]; j++) {
                if(nums[i]%j == 0) {
                    if(nums[i]/j == j) {
                        if(vis[j]) fact[i] += 1;
                    }
                    else {
                        if(vis[nums[i]/j]) fact[i]++;
                        if(vis[j]) fact[i]++;
                    }
                }
            }
        }
        // for(auto i: fact) cout<<i<<" ";
        // cout<<endl;
        vector<int> left(n,0),right(n,n-1);
        stack<int> st;
        for(int i = 0; i<n; i++) {
            while(!st.empty() && fact[st.top()] < fact[i]) {
                st.pop();
            }
            if(!st.empty()) left[i] = st.top()+1;
            st.push(i);

        }
        // for(auto i: left) cout<<i<<" ";
        // cout<<endl;
        stack<int> st2;
        for(int i = n-1; i>=0; i--) {
            while(!st2.empty() && fact[st2.top()] <= fact[i]) {
                st2.pop();
            }
            if(!st2.empty()) right[i] = st2.top()-1;
            st2.push(i);
        }
        // for(auto i: right) cout<<i<<" ";
        // cout<<endl;
        vector<pair<int,int>> temp;
        for(int i = 0; i<n; i++) {
            temp.push_back({nums[i],i});
        }
        sort(temp.begin(),temp.end(),greater<pair<int,int>>());
        long long ans = 1;
        for(auto i: temp) {
            long long cnt = i.second-left[i.second]+1;
            cnt *= right[i.second]-i.second+1;
            cnt = min(cnt,(long long)k);
            //cout<<i.first<<" "<<cnt<<endl;
            ans *= power(i.first,cnt);
            ans %= mod;
            k -= cnt;
            if(k <= 0) break;
        }
        return ans;
    }
};