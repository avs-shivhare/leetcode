class Solution {
public:
    int find(vector<vector<int>> &en,int val) {
        int n = en.size();
        int ans = n;
        int l =0,r = n-1;
        while(l<=r) {
            int mid = (l+r)>>1;
            if(en[mid][0] > val) {
                ans = mid;
                r = mid-1;
            }
            else l = mid+1;
        }
        return ans;
    }
    int maxTwoEvents(vector<vector<int>>& en) {
        sort(en.begin(),en.end());
        int n = en.size();
        int suffix[100001];
        memset(suffix,0,sizeof(suffix));
        suffix[n-1] = en[n-1][2];
        for(int i = n-2; i>=0; i--) {
            suffix[i] = max(en[i][2],suffix[i+1]);
        }
        int ans = 0;
        for(int i = 0; i<n; i++) {
            int x = find(en,en[i][1]);
            if(x != n) ans = max(ans,suffix[x]+en[i][2]);
            else ans = max(ans,en[i][2]);
        }
        return ans;
    }
};