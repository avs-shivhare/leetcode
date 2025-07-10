class Solution {
public:
    int maxFreeTime(int ev, vector<int>& st, vector<int>& en) {
        int temp = 0;
        temp = st[0];
        int n = st.size();
        int ans = 0;
        ans = max(ans,temp);
        for(int i = 0; i<n; i++) {
            if(temp >= en[i]-st[i]) {
                int prev = (i>0 ? en[i-1]: (en[i]-st[i]));
                int next = (i+1 < n ? st[i+1] : ev);
                ans = max(ans,next-prev);
                //cout<<i<<" "<<next<<" "<<prev<<endl;
            }
            int prev = (i > 0 ? en[i-1]+(en[i]-st[i]) : 0+(en[i]-st[i]));
            int next = (i+1 < n ? st[i+1] : ev);
            ans = max(ans,next-prev);
            if(i > 0) temp = max(temp,st[i]-en[i-1]);
            ans = max(ans,temp);
        }
        temp = ev-en[n-1];
        ans = max(ans,temp);
        for(int i = n-1; i>=0; i--) {
            if(temp >= en[i]-st[i]) {
                int prev = (i > 0 ? en[i-1] : 0);
                int next = (i+1 < n ? st[i+1] : ev-(en[i]-st[i]));
                ans = max(ans,next-prev);
            }
            int next = (i+1 < n ? st[i+1]-(en[i]-st[i]) : ev-(en[i]-st[i]));
            int prev = (i > 0 ? en[i-1] : 0);
            ans = max(ans,next-prev);
            if(i+1<n) temp = max(temp,st[i+1]-en[i]);
            ans = max(ans,temp);
        }
        return ans;
    }
};