class Solution {
public:
    int maxFreeTime(int ev, int k, vector<int>& st, vector<int>& en) {
        vector<int> temp;
        temp.push_back(st[0]);
        int n = st.size();
        for(int i = 1; i<n; i++) {
            temp.push_back(st[i]-en[i-1]);
        }
        temp.push_back(ev-en[n-1]);
        int l = 0,r = 0;
        n = temp.size();
        int sum = 0;
        int ans = 0;
        while(r<n) {
            sum += temp[r];
            while(l<r && r-l+1 > k+1) {
                sum -= temp[l];
                l++;
            }
            if(r-l+1 <= k+1) {
                ans = max(ans,sum);
            }
            r++;
        }
        return ans;
    }
};