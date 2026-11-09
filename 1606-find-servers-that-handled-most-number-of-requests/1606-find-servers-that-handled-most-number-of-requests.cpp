class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arr, vector<int>& load) {
        int n = arr.size();
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> q;
        set<int> st;
        for(int i = 0; i<k; i++) {
            st.insert(i);
        }
        vector<int> cnt(k,0);
        for(int i = 0; i<n; i++) {
            while(!q.empty() && q.top().first <= arr[i]) {
                st.insert(q.top().second);
                q.pop();
            }
            if(st.empty()) continue;
            int index = i%k;
            auto x = st.lower_bound(index);
            if(x == st.end()) {
                x = st.begin();
                if(x != st.end()) {
                    cnt[*x]++;
                    q.push({1ll*arr[i]+load[i],*x});
                    st.erase(x);
                }
            }
            else {
                //cout<<*x<<endl;
                cnt[*x]++;
                q.push({1ll*arr[i]+load[i],*x});
                st.erase(x);
            }
        }
        int maxi = *max_element(cnt.begin(),cnt.end());
        vector<int> ans;
        for(int i = 0; i<k; i++) {
            if(cnt[i] == maxi) ans.push_back(i);
        }
        return ans;
    }
};